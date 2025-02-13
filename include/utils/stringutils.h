/************************************************************************************
      
 *                 Copyright (C) 2021 - 2023, Barca, Inc. 
 
 *    Email: <opensource@barca.com>  GitHub: @BarcaWebCloud. 
 *    Project: BSCAN to scanner MotherBoards. CPU, Memory Ram, SO and more
 
 * This software is licensed as described in the file COPYING, which                    
 * you should have received as part of this distribution. The terms                     
 * are also available at https://project-barca.github.io/docs/copyright.html.           
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell             
 * copies of the Software, and permit persons to whom the Software is                   
 * furnished to do so, under the terms of the COPYING file.                             
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY            
 * KIND, either express or implied.                                                      
 *
 **************************************************************************************/
#pragma once

#include <codecvt>
#include <cstring>
#include <locale>
#include <string>
#include <numeric>
#include <vector>
#include <sstream>

/**
 * remove all white spaces (' ', '\t', '\n') from start and end of input
 * inplace!
 * @param input
 */
inline void strip(std::string& input) {
  if (input.empty()) {
    return;
  }
  // optimization for input size == 1
  if (input.size() == 1) {
    if (input[0] == ' ' || input[0] == '\t' || input[0] == '\n') {
      input = "";
      return;
    } else {
      return;
    }
  }
  size_t start_index = 0;
  while (true) {
    char c = input[start_index];
    if (c != ' ' && c != '\t' && c != '\n') {
      break;
    }
    start_index++;
  }
  size_t end_index = input.size() - 1;
  while (true) {
    char c = input[end_index];
    if (c != ' ' && c != '\t' && c != '\n') {
      break;
    }
    end_index--;
  }
  if (end_index <= start_index) {
    input.assign("");
    return;
  }
  input.assign(input.begin() + start_index, input.begin() + end_index + 1);
}

/**
 * Count occurrences of a substring in input
 * @param input
 * @param substring
 * @return
 */
inline unsigned count_substring(const std::string& input, const std::string& substring) {
  unsigned occurrences = 0;
  std::string::size_type shift = 0;
  while ((shift = input.find(substring, shift)) != std::string::npos) {
    occurrences++;
    shift += substring.size();
  }
  return occurrences;
}

/**
 * Split input string at delimiter and return result
 * @param input
 * @param delimiter
 * @return
 */
inline std::vector<std::string> split(const std::string& input, const std::string& delimiter) {
  std::vector<std::string> result;
  size_t shift = 0;
  while (true) {
    size_t match = input.find(delimiter, shift);
    result.emplace_back(input.substr(shift, match - shift));
    if (match == std::string::npos) {
      break;
    }
    shift = match + delimiter.size();
  }
  return result;
}

/**
 * Split input string at delimiter (char) and return result
 * @param input
 * @param delimiter
 * @return
 */
inline std::vector<std::string> split(const std::string& input, const char delimiter) {
  std::vector<std::string> result;
  size_t shift = 0;
  while (true) {
    size_t match = input.find(delimiter, shift);
    if (match == std::string::npos) {
      break;
    }
    result.emplace_back(input.substr(shift, match - shift));
    shift = match + 1;
  }
  return result;
}

/**
 * split input at delimiter and return substring at position index.
 * index can be negative, where -1 is the last occurrence.
 * @param input
 * @param delimiter
 * @param index
 * @return
 */
inline std::string split_get_index(const std::string& input, const std::string& delimiter, int index) {
  unsigned occ = count_substring(input, delimiter) + 1;
  index = index < 0 ? static_cast<int>(occ + index) : index;
  if (occ <= index) {
    return "";
  }

  std::string::size_type start_index = 0;
  while (true) {
    if (index == 0) {
      break;
    }
    start_index = input.find(delimiter, start_index) + delimiter.size();
    index--;
  }
  std::string::size_type end_index = input.find(delimiter, start_index);
  if (end_index == std::string::npos) {
    return {input.begin() + static_cast<int64_t>(start_index), input.end()};
  }
  return {input.begin() + static_cast<int64_t>(start_index), input.begin() + static_cast<int64_t>(end_index)};
}

/**
 * Convert windows wstring to string
 * @return
 */
inline std::string wstring_to_string() { return ""; }

/**
 * Convert wstring to string
 * @return
 */
inline std::string wstring_to_std_string(const std::wstring& ws) {
  std::string str_locale = setlocale(LC_ALL, "");
  const wchar_t* wch_src = ws.c_str();
  size_t n_dest_size = wcstombs(NULL, wch_src, 0) + 1;
  char* ch_dest = new char[n_dest_size];
  memset(ch_dest, 0, n_dest_size);
  wcstombs(ch_dest, wch_src, n_dest_size);
  std::string result_text = ch_dest;
  delete[] ch_dest;
  setlocale(LC_ALL, str_locale.c_str());
  return result_text;
}

/**
 * Convert string to int
 * @return
 */
inline int string_to_int(const std::string& string) {
  std::string str_locale = setlocale(LC_ALL, "");
    std::stringstream sstream(string);
    int i;
    sstream >> i;
    return i;
}

/**
 * Replace the std::string::starts_with function only available in C++20 and above.
 * @param str
 * @param prefix
 * @return
 */
template <typename string_type, typename prefix_type>
inline bool starts_with(const string_type& str, const prefix_type& prefix) {
#ifdef __cpp_lib_starts_ends_with
  return str.starts_with(prefix);
#else
  return str.rfind(prefix, 0) == 0;
#endif
}

/**
 * Insert in the string
 * @return
 */
struct between_string {
  std::string sep;
  between_string(const std::string& sep) : sep(sep) {}
  std::string operator()(const std::string& lhs, const std::string& rhs) {
    std::string rz(lhs);
    if(!lhs.empty() && !rhs.empty())
      rz += sep;
    rz += rhs;
    return rz;
  }
};