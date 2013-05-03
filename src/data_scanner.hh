/**
 * Copyright (c) 2007-2012, Timothy Stack
 *
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of Timothy Stack nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __data_scanner_hh
#define __data_scanner_hh

#include <string>

#include "pcrepp.hh"

enum data_token_t {
    DT_INVALID = -1,
    
    DT_URL = 0,
    DT_PATH,
    DT_TIME,
    DT_MAC_ADDRESS,
    DT_QUOTED_STRING,
    // DT_QUALIFIED_NAME,
    
    DT_SEPARATOR,
    DT_COMMA,

    DT_IP_ADDRESS,

    DT_VERSION_NUMBER,
    DT_OCTAL_NUMBER,
    DT_PERCENTAGE,
    DT_NUMBER,
    DT_HEX_NUMBER,

    DT_STRING,
    DT_LINE,
    DT_WHITE,
    DT_DOT,

    DT_GARBAGE,

    DT_TERMINAL_MAX = DT_GARBAGE + 1,

    DNT_KEY = 50,
    DNT_PAIR,
    DNT_VALUE,
    DNT_ROW,
    DNT_UNITS,
    DNT_MEASUREMENT,
    DNT_VARIABLE_KEY,
    DNT_ROWRANGE,
    DNT_DATE_TIME,
    
    DT_ANY = 100,
};

class data_scanner {
public:
    static const char *token2name(data_token_t token);
    
    data_scanner(const std::string &line) :
	ds_line(line),
	ds_pcre_input(ds_line.c_str()) {
    };

    bool tokenize(pcre_context &pc, data_token_t &token_out);

    pcre_input &get_input() { return this->ds_pcre_input; };

private:
    std::string ds_line;
    pcre_input ds_pcre_input;
};

#endif