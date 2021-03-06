/*
Copyright (c) 2014, Intel Corporation

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "device/api/nn_data_0.h"
#include <limits>

    //Fills nn::data's buffer. Object can be filled with const or random value.
    //If random you can specify range.
    void nn_data_populate(
        nn::data<float>* in_out,
        bool const_val = false,
        float const_val_value = 0,  // value valid if const_val = true
        float min_val = (std::numeric_limits<float>::min)(),
        float max_val = (std::numeric_limits<float>::max)());

    void nn_data_populate(
        nn::data<float>* in_out,
        float const_val);

    void nn_data_populate(
        nn::data<float>* in_out,
        float min_val,
        float max_val);

    void nn_data_populate_normal_distribution(
        nn::data<float>* in_out,
        float avg,
        float margin);

    // Checks equality of nn::data.
    // For values less than absoulte_error_limit, absolute error will be counted
    // for others, the relatve error will be counted.
    // Function returns false if error will exceed the threshold.
    // Default values:
    // relative_error_threshold = 1e-3
    // absolute_error_threshold = 1e-6
    // absoulte_error_limit = 1e-4
     bool compare_data(
            nn::data<float>* item,
            nn::data<float>* ref_item,
            float relative_error_threshold = 1e-3,
            float absolute_error_threshold = 1e-6,
            float absoulte_error_limit = 1e-4);
