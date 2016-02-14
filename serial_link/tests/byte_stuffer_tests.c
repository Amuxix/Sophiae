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

byte_stuffer_state_t state;

Describe(ByteStuffer);
BeforeEach(ByteStuffer) {
    init_byte_stuffer_state(&state);
}
AfterEach(ByteStuffer) {}

void recv_frame(uint8_t* data, uint16_t size) {
    mock(data, size);
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
    recv_byte(&state, 5);
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
