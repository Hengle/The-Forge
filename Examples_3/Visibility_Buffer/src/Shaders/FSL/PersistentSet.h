/*
 * Copyright (c) 2017-2025 The Forge Interactive Inc.
 *
 * This file is part of The-Forge
 * (see https://github.com/ConfettiFX/The-Forge).
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

BEGIN_SRT_SET(Persistent)
	DECL_CBUFFER(Persistent, CBUFFER(BlurWeightData), gBlurWeights)
	DECL_BUFFER(Persistent, Buffer(MeshConstants), gMeshConstantsBuffer)
	DECL_BUFFER(Persistent, Buffer(LightData), gLights)
    DECL_BUFFER(Persistent, ByteBuffer, gVertexPositionBuffer)
	DECL_BUFFER(Persistent, ByteBuffer, gVertexTexCoordBuffer)
	DECL_BUFFER(Persistent, ByteBuffer, gVertexNormalBuffer)
	DECL_BUFFER(Persistent, ByteBuffer, gIndexDataBuffer)
    DECL_SAMPLER(Persistent, SamplerState, gTextureSampler)
    DECL_SAMPLER(Persistent, SamplerState, gDepthSampler)
    DECL_SAMPLER(Persistent, SamplerState, gTextureFilter)
#if (SAMPLE_COUNT > 1)
#if FT_MULTIVIEW
    DECL_TEXTURE(Persistent, Tex2DArrayMS(float4, SAMPLE_COUNT), gVBTex)
    DECL_TEXTURE(Persistent, Depth2DArrayMS(float, SAMPLE_COUNT), gDepthTex)
#else
    DECL_TEXTURE(Persistent, Tex2DMS(float4, SAMPLE_COUNT), gVBTex)
    DECL_TEXTURE(Persistent, Depth2DMS(float, SAMPLE_COUNT), gDepthTex)
#endif /*FT_MULTIVIEW*/
#else
#if FT_MULTIVIEW
    DECL_TEXTURE(Persistent, Tex2DArray(float4), gVBTex)
    DECL_TEXTURE(Persistent, Depth2DArray(float), gDepthTex)
#else
    DECL_TEXTURE(Persistent, Tex2D(float4), gVBTex)
    DECL_TEXTURE(Persistent, Depth2D(float), gDepthTex)
#endif /*FT_MULTIVIEW*/
#endif /*SAMPLE_COUNT > 1*/
#if FT_MULTIVIEW
	DECL_TEXTURE(Persistent, Tex2DArray(float4), gDisplayTexture)
#else
	DECL_TEXTURE(Persistent, Tex2D(float4), gDisplayTexture)
#endif
#if FT_MULTIVIEW
    DECL_TEXTURE(Persistent, Tex2DArrayMS(uint2, SAMPLE_COUNT), gMSAAStencil)
#else
    DECL_TEXTURE(Persistent, Tex2DMS(uint2, SAMPLE_COUNT), gMSAAStencil)
#endif
	DECL_TEXTURE(Persistent, TexCube(float4), gSkyboxTex)
	DECL_TEXTURE(Persistent, Tex2D(float), gShadowMap)
	DECL_TEXTURE(Persistent, Tex2D(float4), gGodRayTexture)
	DECL_ARRAY_TEXTURES(Persistent, Tex2D(float4), gDiffuseMaps, MAX_TEXTURE_UNITS)
	DECL_ARRAY_TEXTURES(Persistent, Tex2D(float4), gNormalMaps, MAX_TEXTURE_UNITS)
	DECL_ARRAY_TEXTURES(Persistent, Tex2D(float4), gSpecularMaps, MAX_TEXTURE_UNITS)
END_SRT_SET(Persistent)
