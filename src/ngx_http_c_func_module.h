/**
* @file   ngx_http_c_func_module.h
* @author taymindis <cloudleware2015@gmail.com>
* @date   Sun JAN 28 12:06:52 2018
*
* @brief  A ngx_c_function module for Nginx.
*
* @section LICENSE
*
* Copyright (c) 2018, Taymindis <cloudleware2015@gmail.com>
* 
* This module is licensed under the terms of the BSD license.
* 
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this
*    list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>
#include <stdint.h>

#define ngx_http_c_func_module_version_2 2


#define ngx_http_c_func_content_type_plaintext "text/plain"
#define ngx_http_c_func_content_type_html "text/html; charset=utf-8"
#define ngx_http_c_func_content_type_json "application/json"
#define ngx_http_c_func_content_type_jsonp "application/javascript"
#define ngx_http_c_func_content_type_xformencoded "application/x-www-form-urlencoded"



typedef struct {
	char *req_args; // Uri Args
	u_char *req_body; // Request Body

	/* internal */
	void* __r__;
	void* __log__;
	intptr_t __rc__;
} ngx_http_c_func_ctx_t;

extern void ngx_http_c_func_log_debug(ngx_http_c_func_ctx_t *ctx, const char* msg);
extern void ngx_http_c_func_log_info(ngx_http_c_func_ctx_t *ctx, const char* msg);
extern void ngx_http_c_func_log_warn(ngx_http_c_func_ctx_t *ctx, const char* msg);
extern void ngx_http_c_func_log_err(ngx_http_c_func_ctx_t *ctx, const char* msg);

extern u_char* ngx_http_c_func_get_header(ngx_http_c_func_ctx_t *ctx, const char*key);
extern void* ngx_http_c_func_get_query_param(ngx_http_c_func_ctx_t *ctx, const char *key);
extern void* ngx_http_c_func_palloc(ngx_http_c_func_ctx_t *ctx, size_t size);
extern void* ngx_http_c_func_pcalloc(ngx_http_c_func_ctx_t *ctx, size_t size);

#define ngx_http_c_func_log(loglevel, req_context, ...) ({\
char __buff__[200];\
snprintf(__buff__, 200, ##__VA_ARGS__);\
ngx_http_c_func_log_##loglevel(req_context, __buff__);\
})

extern void ngx_http_c_func_write_resp(
    ngx_http_c_func_ctx_t *ctx,
    uintptr_t status_code,
    const char* status_line,
    const char* content_type,
    const char* resp_content
);