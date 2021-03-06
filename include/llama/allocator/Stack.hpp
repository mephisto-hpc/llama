/* Copyright 2018 Alexander Matthes
 *
 * This file is part of LLAMA.
 *
 * LLAMA is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * LLAMA is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with LLAMA.  If not, see <www.gnu.org/licenses/>.
 */

#pragma once

#include <vector>
#include <stdlib.h>
#include <malloc.h>

namespace llama
{

namespace allocator
{

/** Allocator to allocate memory for a \ref View in the \ref Factory on the
 *  stack.
 * \tparam reserved the amount of memory is needed to be known at compile time
 *  for performance reasons, this can be gotten at compile time with \ref SizeOf
 * \see tempAlloc, OneOnStackFactory
 */
template<
    std::size_t reserved
>
struct Stack
{
    /// primary type of this allocator is `unsigned char`
    using PrimType = unsigned char;
    /// blob type of this allocator is `llama::Array< PrimType, reserved >`
    using BlobType = Array<
        PrimType,
        reserved
    >;
    /// the optional allocation parameter is ignored
    using Parameter = int; //not used
    static
    LLAMA_FN_HOST_ACC_INLINE
    auto
    allocate(
        std::size_t,
        Parameter const
    )
    -> BlobType
    {
        return BlobType();
    }
};

} // namespace allocator

} // namespace llama
