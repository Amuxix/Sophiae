/*
The MIT License (MIT)

Copyright (c) 2016 Fred Sundvik

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <cgreen/cgreen.h>
#include <cgreen/mocks.h>
#include "protocol/byte_stuffer.h"
#include "protocol/byte_stuffer.c"
#include "protocol/frame_validator.h"
#include "protocol/physical.h"

static byte_stuffer_state_t state;
static uint8_t sent_data[MAX_FRAME_SIZE*2];
static uint16_t sent_data_size;

Describe(ByteStuffer);
BeforeEach(ByteStuffer) {
    init_byte_stuffer_state(&state);
    sent_data_size = 0;
}
AfterEach(ByteStuffer) {}

void recv_frame(uint8_t* data, uint16_t size) {
    mock(data, size);
}

void send_data(const uint8_t* data, uint16_t size) {
    memcpy(sent_data + sent_data_size, data, size);
    sent_data_size += size;
}

Ensure(ByteStuffer, receives_no_frame_for_a_single_zero_byte) {
    never_expect(recv_frame);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_no_frame_for_a_single_FF_byte) {
    never_expect(recv_frame);
    recv_byte(&state, 0xFF);
}

Ensure(ByteStuffer, receives_no_frame_for_a_single_random_byte) {
    never_expect(recv_frame);
    recv_byte(&state, 0x4A);
}

Ensure(ByteStuffer, receives_no_frame_for_a_zero_length_frame) {
    never_expect(recv_frame);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_single_byte_valid_frame) {
    uint8_t expected[] = {0x37};
    expect(recv_frame,
        when(size, is_equal_to(1)),
        when(data, is_equal_to_contents_of(expected, 1))
    );
    recv_byte(&state, 2);
    recv_byte(&state, 0x37);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_three_bytes_valid_frame) {
    uint8_t expected[] = {0x37, 0x99, 0xFF};
    expect(recv_frame,
        when(size, is_equal_to(3)),
        when(data, is_equal_to_contents_of(expected, 3))
    );
    recv_byte(&state, 4);
    recv_byte(&state, 0x37);
    recv_byte(&state, 0x99);
    recv_byte(&state, 0xFF);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_single_zero_valid_frame) {
    uint8_t expected[] = {0};
    expect(recv_frame,
        when(size, is_equal_to(1)),
        when(data, is_equal_to_contents_of(expected, 1))
    );
    recv_byte(&state, 1);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_valid_frame_with_zeroes) {
    uint8_t expected[] = {5, 0, 3, 0};
    expect(recv_frame,
        when(size, is_equal_to(4)),
        when(data, is_equal_to_contents_of(expected, 4))
    );
    recv_byte(&state, 2);
    recv_byte(&state, 5);
    recv_byte(&state, 2);
    recv_byte(&state, 3);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_two_valid_frames) {
    uint8_t expected1[] = {5, 0};
    uint8_t expected2[] = {3};
    expect(recv_frame,
        when(size, is_equal_to(2)),
        when(data, is_equal_to_contents_of(expected1, 2))
    );
    expect(recv_frame,
        when(size, is_equal_to(1)),
        when(data, is_equal_to_contents_of(expected2, 1))
    );
    recv_byte(&state, 2);
    recv_byte(&state, 5);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
    recv_byte(&state, 2);
    recv_byte(&state, 3);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_valid_frame_after_unexpected_zero) {
    uint8_t expected[] = {5, 7};
    expect(recv_frame,
        when(size, is_equal_to(2)),
        when(data, is_equal_to_contents_of(expected, 2))
    );
    recv_byte(&state, 3);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
    recv_byte(&state, 3);
    recv_byte(&state, 5);
    recv_byte(&state, 7);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_valid_frame_after_unexpected_non_zero) {
    uint8_t expected[] = {5, 7};
    expect(recv_frame,
        when(size, is_equal_to(2)),
        when(data, is_equal_to_contents_of(expected, 2))
    );
    recv_byte(&state, 2);
    recv_byte(&state, 9);
    recv_byte(&state, 4); // This should have been zero
    recv_byte(&state, 0);
    recv_byte(&state, 3);
    recv_byte(&state, 5);
    recv_byte(&state, 7);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_a_valid_frame_with_over254_non_zeroes_and_then_end_of_frame) {
    uint8_t expected[254];
    int i;
    for (i=0;i<254;i++) {
        expected[i] = i + 1;
    }
    expect(recv_frame,
        when(size, is_equal_to(254)),
        when(data, is_equal_to_contents_of(expected, 254))
    );
    recv_byte(&state, 0xFF);
    for (i=0;i<254;i++) {
        recv_byte(&state, i+1);
    }
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_a_valid_frame_with_over254_non_zeroes_next_byte_is_non_zero) {
    uint8_t expected[255];
    int i;
    for (i=0;i<254;i++) {
        expected[i] = i + 1;
    }
    expected[254] = 7;
    expect(recv_frame,
        when(size, is_equal_to(255)),
        when(data, is_equal_to_contents_of(expected, 255))
    );
    recv_byte(&state, 0xFF);
    for (i=0;i<254;i++) {
        recv_byte(&state, i+1);
    }
    recv_byte(&state, 2);
    recv_byte(&state, 7);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_a_valid_frame_with_over254_non_zeroes_next_byte_is_zero) {
    uint8_t expected[255];
    int i;
    for (i=0;i<254;i++) {
        expected[i] = i + 1;
    }
    expected[254] = 0;
    expect(recv_frame,
        when(size, is_equal_to(255)),
        when(data, is_equal_to_contents_of(expected, 255))
    );
    recv_byte(&state, 0xFF);
    for (i=0;i<254;i++) {
        recv_byte(&state, i+1);
    }
    recv_byte(&state, 1);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_two_long_frames_and_some_more) {
    uint8_t expected[515];
    int i;
    int j;
    for (j=0;j<2;j++) {
        for (i=0;i<254;i++) {
            expected[i+254*j] = i + 1;
        }
    }
    for (i=0;i<7;i++) {
        expected[254*2+i] = i + 1;
    }
    expect(recv_frame,
        when(size, is_equal_to(515)),
        when(data, is_equal_to_contents_of(expected, 510))
    );
    recv_byte(&state, 0xFF);
    for (i=0;i<254;i++) {
        recv_byte(&state, i+1);
    }
    recv_byte(&state, 0xFF);
    for (i=0;i<254;i++) {
        recv_byte(&state, i+1);
    }
    recv_byte(&state, 8);
    recv_byte(&state, 1);
    recv_byte(&state, 2);
    recv_byte(&state, 3);
    recv_byte(&state, 4);
    recv_byte(&state, 5);
    recv_byte(&state, 6);
    recv_byte(&state, 7);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, receives_an_all_zeros_frame_that_is_maximum_size) {
    uint8_t expected[MAX_FRAME_SIZE] = {};
    expect(recv_frame,
        when(size, is_equal_to(MAX_FRAME_SIZE)),
        when(data, is_equal_to_contents_of(expected, MAX_FRAME_SIZE))
    );
    int i;
    recv_byte(&state, 1);
    for(i=0;i<MAX_FRAME_SIZE;i++) {
       recv_byte(&state, 1);
    }
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, doesnt_recv_a_frame_thats_too_long_all_zeroes) {
    uint8_t expected[1] = {0};
    never_expect(recv_frame);
    int i;
    recv_byte(&state, 1);
    for(i=0;i<MAX_FRAME_SIZE;i++) {
       recv_byte(&state, 1);
    }
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, received_frame_is_aborted_when_its_too_long) {
    uint8_t expected[1] = {1};
    expect(recv_frame,
        when(size, is_equal_to(1)),
        when(data, is_equal_to_contents_of(expected, 1))
    );
    int i;
    recv_byte(&state, 1);
    for(i=0;i<MAX_FRAME_SIZE;i++) {
       recv_byte(&state, 1);
    }
    recv_byte(&state, 2);
    recv_byte(&state, 1);
    recv_byte(&state, 0);
}

Ensure(ByteStuffer, send_zero_size_frame_does_nothing) {
    assert_that(sent_data_size, is_equal_to(0));
    send_frame(NULL, 0);
}

Ensure(ByteStuffer, send_one_byte_frame) {
    uint8_t data[] = {5};
    send_frame(data, 1);
    assert_that(sent_data_size, is_equal_to(3));
    uint8_t expected[] = {2, 5, 0};
    assert_that(sent_data, is_equal_to_contents_of(expected, 3));
}

Ensure(ByteStuffer, send_two_byte_frame) {
    uint8_t data[] = {5, 0x77};
    send_frame(data, 2);
    assert_that(sent_data_size, is_equal_to(4));
    uint8_t expected[] = {3, 5, 0x77, 0};
    assert_that(sent_data, is_equal_to_contents_of(expected, 4));
}
