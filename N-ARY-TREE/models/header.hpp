#pragma once
#include <functional>
#include <iostream>

template<typename KeyT>
using hash_func = std::function<size_t (KeyT)>;