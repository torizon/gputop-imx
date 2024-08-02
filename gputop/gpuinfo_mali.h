/*
 * Copyright NXP 2024
 *
 * Copyright (c) 2023 ARM Limited.
 *
 * SPDX-License-Identifier: MIT

 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sub license,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef __TOP_MALI_H
#define __TOP_MALI_H

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct gpuinfo_mali
{
    /** GPU name */
    const char* gpu_name;

    /** GPU architecture name */
    const char* architecture_name;

    /** GPU ID */
    uint32_t gpu_id;

    /** Number of shader cores */
    uint32_t num_shader_cores;

    /** Shader core topology mask */
    uint64_t shader_core_mask;

    /** Number of L2 cache slices */
    uint32_t num_l2_slices;

    /** L2 cache size, summed for all slices, in bytes */
    uint32_t num_l2_bytes;

    /** GPU external bus width per cache slice, in bits */
    uint32_t num_bus_bits;

    /** Number of execution engines per core */
    uint32_t num_exec_engines;

    /** Maximum number of 32-bit floating-point FMAs per clock per core */
    uint32_t num_fp32_fmas_per_cy;

    /** Maximum number of 16-bit floating-point FMAs per clock per core */
    uint32_t num_fp16_fmas_per_cy;

    /** Maximum number of bilinear filtered texels per clock per core */
    uint32_t num_texels_per_cy;

    /** Maximum number of output pixels per clock per core */
    uint32_t num_pixels_per_cy;
    /** Total Avaliable gpu memory **/
    uint32_t  gpu_avail_mem_size;
};


/** Kbase ioctl interface type. */
enum class iface_type {
    /** Pre R21 kernel */
    pre_r21=0,
    /** Post R21 kernel (inclusive) */
    post_r21
};

/** Check the Mali kernel driver interface version. */
bool check_mali_version();

/** Configure Mali kernel driver connection flags. */
bool set_mali_flags();

/** Query properties and store them locally. */
bool init_mali_props();

/** Get device constants from the old format ioctl. */
bool init_props_mali_pre_r21();

/** Get device constants from the new format ioctl. */
bool init_props_mali_post_r21();

#endif /* end __TOP_MALI_H */
