/* This file is automatically generated by SCOptimizer */

#include "mcinfer.h"

fuzzy_model model={

0, /* model_ready set to OK */
1, /* engine code (algorithm type) */
1, /* min_inference_mode */
1, /* database type */
2, /* number of input variables */
4, /* number of output variables */

/* Input variable normalization parameters */
{{0.000861f,-0.070568f},{0.001063f,-0.232731f}},

/* Output variable normalization parameters */
{{0.020000f,-0.100000f},{0.025000f,-0.250000f},{0.025641f,-2.846154f},{0.011111f,-1.000000f}},

/* number of input MF's per variable*/ 
{15,15},
/* input MF paramteres */ 
{
	{triangular,0.048408f,0,0.093911f,0.148171f},{triangular,0.201700f,0,0.149215f,0.114572f},{triangular,0.297547f,0,0.071373f,0.076381f},{triangular,0.368653f,0,0.061564f,0.081181f},{triangular,0.453959f,0,0.084312f,0.061773f},{triangular,0.504626f,0,0.036521f,0.083686f},{triangular,0.587565f,0,0.077216f,0.083059f},{triangular,0.651463f,0,0.040904f,0.056764f},{triangular,0.701162f,0,0.039652f,0.043825f},{triangular,0.744837f,0,0.040904f,0.045077f},{triangular,0.794750f,0,0.051756f,0.055095f},{triangular,0.854131f,0,0.060103f,0.037565f},{triangular,0.887263f,0,0.026713f,0.063442f},{triangular,0.935886f,0,0.030886f,0.041738f},{triangular,0.979776f,0,0.043408f,0.039234f},
	{triangular,0.023512f,0,0.046741f,0.114873f},{triangular,0.170430f,0,0.177195f,0.095331f},{triangular,0.254915f,0,0.072621f,0.103782f},{triangular,0.359857f,0,0.104838f,0.050438f},{triangular,0.435707f,0,0.100349f,0.070772f},{triangular,0.531615f,0,0.119890f,0.070244f},{triangular,0.578108f,0,0.022182f,0.020070f},{triangular,0.598565f,0,0.020598f,0.031161f},{triangular,0.625399f,0,0.022182f,0.046477f},{triangular,0.677471f,0,0.057040f,0.049646f},{triangular,0.725027f,0,0.044893f,0.050174f},{triangular,0.776036f,0,0.051231f,0.033274f},{triangular,0.824389f,0,0.062850f,0.070244f},{triangular,0.886504f,0,0.053237f,0.053449f},{triangular,0.954152f,0,0.081034f,0.091144f}
	},

/* number of output MF's per variable*/ 
{5,5,5,5},
/* output MF paramteres */ 
{
	{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},
	{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},
	{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},
	{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0},{exact,0.000000f,0,0,0}
	},

/* Rule database */
225, /*number of rules */

/* index */
{0}, /* empty */
/* database */
{
	0xB8,0xD0,0x37,0x3D,0x86,0xD4,0x85,0x3E,0xE9,0x80,0x68,0x3E,0xB2,0x48,0xB2,0x3D,0xAC,0xB3,0x2B,0x3F,0xAC,0x48,0x2C,0x3F,0xA7,0x8C,0x26,0x3F,0xC9,0x51,0x49,0x3F,0xA2,0xA0,0x21,0x3E,0xF7,0x6A,0x77,0x3F,0x8F,0xA8,0x0E,0x3F,0xF8,0x84,0x77,0x3E,0xBA,0x33,0x6D,0x3F,0x7C,0x2F,0x7C,0x3F,0x2E,0x98,0x7A,0x3F,0x9D,0x13,0x36,0x3F,0x8E,0x60,0x74,0x3F,0x39,0x34,0x6C,0x3F,0xC0,0xE4,0x73,0x3F,0x5E,0x16,0x2D,0x3F,0x74,0x58,0x74,0x3F,0x8C,0xDD,0x72,0x3F,0xB0,0xC3,0x7C,0x3F,0xBE,0x82,0x56,0x3F,0xBF,0x23,0x3F,0x3F,0xC8,0xD2,0x47,0x3F,0xF6,0x98,0x75,0x3F,0xD5,0x60,0x55,0x3D,0xB3,0xF4,0x7F,0x3F,0x40,0xFC,0x72,0x3F,0xA3,0x4B,0x70,0x3F,0xD6,0x78,0x55,0x3F,0x60,0x3A,0x7A,0x3F,0x12,0x60,0x78,0x3F,0xF0,0x20,0x71,0x3F,0x3B,0xA3,0x53,0x3F,0xAC,0xD5,0x78,0x3F,0xD0,0xC6,0x69,0x3F,0x0A,0xA0,0x71,0x3F,0x26,0x9D,0x68,0x3F,0x22,0xA1,0x6E,0x3F,0x19,0x28,0x65,0x3F,0xF8,0xAB,0x77,0x3F,0x34,0x75,0x64,0x3F,0xCC,0xE4,0x7F,0x3F,0x9A,0x94,0x4D,0x3F,0xCA,0x8F,0x59,0x3F,0x25,0xCD,0x68,0x3F,0x8E,0x1F,0x75,0x3F,0xCC,0x9B,0x7F,0x3F,0x08,0xF4,0x7D,0x3F,0x9C,0x4E,0x74,0x3F,0xD4,0x71,0x7D,0x3F,0x07,0x43,0x53,0x3F,0x44,0xA1,0x48,0x3F,0x17,0x4D,0x7D,0x3F,0xE3,0x98,0xED,0x3E,0x10,0xB2,0xDC,0x3E,0xC3,0xEB,0x0F,0x3F,0x4B,0x5B,0x7E,0x3F,0xE4,0x29,0x64,0x3F,0x94,0x92,0x93,0x3E,0xB1,0x3F,0x31,0x3F,0xA7,0xB0,0x26,0x3D,
	0xDC,0x2B,0x5C,0x3F,0xF0,0x08,0xF0,0x3E,0xF0,0xD0,0xEF,0x3E,0xBA,0x00,0xBA,0x3C,0x72,0x91,0x72,0x3F,0x52,0x89,0x6B,0x3F,0x07,0x7E,0x6E,0x3F,0x38,0xD6,0x0C,0x3F,0x0F,0x91,0x75,0x3F,0xE2,0x51,0x7B,0x3F,0xDD,0xFC,0x76,0x3F,0x01,0x0D,0x31,0x3F,0x32,0x55,0x7E,0x3F,0xFA,0x62,0x7A,0x3F,0x36,0x7B,0x44,0x3F,0x2D,0x97,0x1B,0x3F,0x5C,0x96,0x75,0x3F,0x58,0x42,0x3E,0x3F,0x75,0x4C,0x61,0x3F,0x19,0x60,0x1E,0x3F,0xF4,0xD5,0x73,0x3F,0xDF,0xDB,0x5E,0x3F,0x98,0xA5,0x17,0x3F,0xAD,0x5B,0x2D,0x3F,0x76,0xD4,0xA8,0x3E,0x39,0x2E,0x39,0x3F,0x90,0x81,0x23,0x3F,0x8D,0x14,0x50,0x3F,0x43,0x97,0x42,0x3F,0x98,0xB8,0x17,0x3F,0x4E,0x74,0xE7,0x3E,0x28,0xDE,0x49,0x3F,0xB5,0x9B,0x34,0x3F,0xF1,0x95,0xF0,0x3E,0xAC,0x78,0x1D,0x3F,0xC7,0x54,0x4F,0x3F,0xA8,0x61,0xA7,0x3E,0x42,0x40,0x42,0x3F,0x50,0xA3,0x16,0x3F,0x99,0x5F,0x56,0x3F,0xB3,0x8E,0xB2,0x3E,0xAE,0x29,0x2E,0x3F,0x52,0x57,0xCD,0x3E,0x4A,0x2B,0x62,0x3F,0xD1,0xCB,0xD0,0x3E,0x46,0x7B,0x45,0x3F,0x80,0x1E,0x33,0x3F,0x40,0x3B,0x6D,0x3F,0x3C,0xEF,0x97,0x3E,0xF5,0xDC,0x74,0x3F,0x95,0xDC,0x01,0x3F,0xFD,0xE7,0x71,0x3F,0xFE,0x09,0xA2,0x3E,0xE4,0x5D,0x64,0x3F,0x86,0xD3,0x18,0x3F,0xCB,0x7A,0x7E,0x3F,0xFA,0x34,0x7A,0x3F,0xC0,0xE4,0x3F,0x3F,0xB3,0xF2,0xB2,0x3E,0xE8,0x91,0x67,0x3F,0x9D,0xBC,0x69,0x3F,0xA3,0xA8,0x6F,0x3F,0xA0,0x88,0x6D,0x3F,0xD0,0xA6,0x13,0x3F,
	0x6A,0xD7,0x6A,0x3F,0xCF,0x96,0x68,0x3F,0x6D,0xDF,0x6D,0x3F,0x1A,0xAC,0x15,0x3F,0xBB,0x6A,0x6E,0x3F,0x20,0xB5,0x6C,0x3F,0xFE,0x9D,0x7D,0x3F,0x35,0xA0,0xE9,0x3E,0x32,0x8E,0x4B,0x3F,0x2E,0x88,0x14,0x3F,0x2C,0xF8,0xF6,0x3E,0x4F,0x1E,0x13,0x3F,0x0B,0xBF,0x0A,0x3F,0xDC,0x48,0xDC,0x3E,0x9E,0x1D,0xDD,0x3E,0x14,0x54,0x38,0x3F,0xCA,0x7E,0x4A,0x3F,0xE4,0xA8,0x63,0x3F,0x94,0x40,0x94,0x3C,0x9E,0x2A,0x1E,0x3F,0x8A,0x0A,0xBD,0x3E,0x89,0x72,0x55,0x3F,0xAF,0xFE,0x0E,0x3F,0x9E,0x2D,0x2E,0x3F,0xAE,0x6B,0xAD,0x3E,0xD4,0x6D,0x3A,0x3F,0x86,0xC9,0x19,0x3F,0xAA,0xB1,0x32,0x3F,0xAF,0x84,0xAE,0x3E,0x50,0x20,0x4F,0x3F,0xAE,0x92,0x2F,0x3F,0xF6,0xAB,0x4A,0x3F,0x18,0xAB,0xE3,0x3E,0xA0,0xED,0x9F,0x3E,0x4E,0xE8,0xE9,0x3E,0x0A,0x2B,0x3D,0x3F,0x21,0x5B,0x07,0x3F,0x02,0x46,0x1B,0x3F,0xDB,0x00,0xDF,0x3E,0x87,0x6E,0x66,0x3F,0x5C,0xFE,0xF4,0x3E,0x86,0x2D,0x39,0x3D,0x3A,0x1D,0x64,0x3E,0x74,0xE9,0x66,0x3F,0xC0,0x78,0x0C,0x3F,0x92,0x0D,0x44,0x3C,0xEB,0xA3,0x16,0x3E,0x38,0x6C,0x53,0x3F,0xFA,0xA1,0x12,0x3F,0x6B,0x9A,0x50,0x3B,0x4F,0x48,0xDD,0x3C,0xC0,0x51,0x78,0x3F,0xDE,0x36,0x78,0x3F,0x45,0x4F,0x78,0x3F,0x44,0x35,0x77,0x3F,0x4A,0x90,0x04,0x3F,0x2A,0x7A,0x76,0x3F,0xAF,0x88,0x7B,0x3F,0x19,0x39,0x67,0x3F,0x50,0x2A,0x10,0x3F,0xAD,0x84,0x79,0x3F,0xC4,0x0C,0x77,0x3F,0xEC,0x2E,0x6D,0x3F,0xF5,0xA7,0xFE,0x3E,
	0xAF,0xB1,0x7B,0x3F,0xAC,0x0E,0x79,0x3F,0xF8,0x6C,0x78,0x3F,0xAA,0xF1,0x20,0x3F,0xB1,0x2B,0xB0,0x3E,0x94,0x6C,0x14,0x3F,0xEC,0xC0,0x27,0x3F,0x09,0x05,0x16,0x3F,0x83,0xE8,0x02,0x3F,0x2E,0xD1,0x60,0x3F,0xD2,0x99,0x18,0x3F,0x2A,0x08,0x29,0x3F,0x13,0xB2,0xDF,0x3E,0x33,0x7E,0x98,0x3D,0x34,0xD7,0x2B,0x3E,0x17,0x4C,0x1E,0x3F,0xFC,0x1A,0xFB,0x3E,0x49,0x32,0xAE,0x3D,0x96,0x0D,0x28,0x3E,0xC6,0x0F,0x34,0x3F,0x5C,0x95,0xF5,0x3E,0x73,0xF9,0xA4,0x3D,0x6C,0x0E,0x94,0x3C,0x8E,0x60,0x27,0x3F,0xF7,0x26,0x10,0x3F,0x96,0x0D,0x48,0x3D,0xB4,0x81,0x45,0x3E,0x11,0x99,0x32,0x3F,0x20,0xEB,0x05,0x3F,0x52,0xA7,0xEA,0x3B,0xCC,0x5A,0x2C,0x3D,0x1C,0x54,0x3E,0x3F,0x43,0x87,0xDC,0x3E,0x29,0x47,0xC1,0x3D,0x5E,0xEE,0x26,0x3E,0xA0,0x0B,0x30,0x3F,0x2D,0x8C,0xF9,0x3E,0x37,0xEF,0x4E,0x3D,0x2F,0x95,0x5B,0x3D,0xC5,0xCC,0x5C,0x3F,0xB4,0x5F,0x80,0x3E,0x52,0x8D,0x04,0x3D,0x43,0x71,0x55,0x3D,0x9B,0xE0,0x74,0x3F,0x59,0x3E,0xBE,0x3D,0xB5,0x86,0x34,0x3E,0x1C,0xF2,0x01,0x3D,0xF6,0x8E,0x75,0x3F,0xFF,0x0E,0x7F,0x3F,0xD1,0xDF,0x50,0x3F,0xE7,0xEF,0x66,0x3F,0xB7,0xFB,0x68,0x3E,0xFC,0x9A,0x7B,0x3F,0xF7,0x44,0x77,0x3F,0xFC,0x73,0x7C,0x3F,0xCD,0xA1,0x98,0x3E,0xAE,0x9A,0x2D,0x3F,0xD6,0x1B,0x56,0x3F,0xD9,0xAD,0x58,0x3F,0xF0,0x57,0xBB,0x3E,0x8D,0x72,0x8D,0x3E,0xCE,0xC1,0x4D,0x3F,0xC0,0x9B,0x2B,0x3F,0xB2,0x1B,0xE3,0x3E,
	0x9D,0x45,0x9D,0x3E,0xB5,0xEA,0x4D,0x3F,0x89,0x69,0x0A,0x3F,0x39,0x3F,0x24,0x3F,0x52,0x3D,0x05,0x3F,0x3A,0xFA,0x1F,0x3E,0x66,0xA1,0xB1,0x3E,0x28,0xD0,0x01,0x3F,0x61,0xB9,0x93,0x3E,0x54,0x3D,0x06,0x3D,0xF1,0x7B,0xA2,0x3C,0x17,0xC5,0xD0,0x3E,0x2E,0x5D,0x14,0x3F,0x25,0x3B,0xBD,0x3D,0x14,0x03,0x8D,0x3C,0xC4,0xAE,0x43,0x3F,0xBA,0x5E,0xB9,0x3E,0x5E,0x67,0xF6,0x39,0xC6,0x21,0x2F,0x3E,0xB2,0x1B,0x3A,0x3F,0xFF,0xEE,0x17,0x3F,0xC7,0x0C,0xC6,0x3D,0xC9,0xDA,0x23,0x3E,0xD7,0x5B,0x2E,0x3F,0x43,0xAA,0x29,0x3D,0x4B,0xD7,0x64,0x3D,0x1A,0x9A,0x00,0x3C,0x85,0x35,0x38,0x3D,0xEF,0x60,0xED,0x3C,0xD5,0xA2,0x54,0x3E,0xDD,0xA8,0x5C,0x3D,0x21,0xD2,0x06,0x3F,0x30,0x97,0xC8,0x3D,0xF9,0xB6,0xF8,0x3D,0x78,0x0D,0xAB,0x3B,0x56,0xC7,0x4C,0x3F,0x45,0xDA,0x2A,0x3D,0xB0,0x85,0x2F,0x3E,0xD3,0x08,0x53,0x3D,0xFD,0xE0,0x48,0x3F,0x75,0xFD,0x26,0x3D,0x94,0x79,0x14,0x3E,0x73,0x8D,0xA5,0x3B,0xF9,0xA8,0x78,0x3F,0xF9,0xB1,0x78,0x3F,0xF9,0x25,0x79,0x3F,0xE3,0xF9,0x62,0x3F,0xDA,0x6C,0xD9,0x3E,0xF5,0x3B,0x75,0x3F,0xFA,0xA0,0x79,0x3F,0xFD,0x66,0x7D,0x3F,0x12,0x8E,0xE9,0x3E,0x9C,0xAA,0x9B,0x3E,0xFE,0x25,0x7E,0x3F,0x4B,0x50,0x72,0x3E,0x18,0xFB,0xBB,0x3E,0xC3,0xDB,0xC2,0x3E,0xD5,0x13,0x55,0x3F,0x3D,0x83,0x3E,0x3F,0x61,0xF3,0x12,0x3F,0x20,0x48,0xEC,0x3E,0x74,0xC5,0x0C,0x3F,0xBE,0x9D,0xEA,0x3E,0xC3,0x08,0xC1,0x3E,
	0xC9,0x4B,0xFB,0x3E,0x96,0x82,0x7A,0x3D,0x7F,0x96,0xB0,0x3D,0x83,0x99,0x07,0x3F,0x63,0x7A,0xC9,0x3C,0x84,0x8A,0x6A,0x3D,0x55,0xBD,0x87,0x3C,0xE2,0x30,0xE2,0x3C,0x0E,0xEC,0x5A,0x3D,0x55,0x65,0x88,0x3D,0xCB,0x78,0x4A,0x3D,0xE7,0x7F,0xB3,0x3D,0xB2,0x8D,0x64,0x3D,0x60,0x22,0xC6,0x3D,0x6E,0x72,0x54,0x3D,0xC9,0xBB,0x95,0x3D,0x75,0x2D,0x27,0x3C,0xD0,0xEB,0x4F,0x3E,0x4E,0x65,0x01,0x3D,0xBB,0x15,0x8D,0x3E,0xBA,0xCD,0x6B,0x3B,0xDB,0x86,0xDA,0x3D,0x89,0x01,0xBC,0x3D,0x9A,0x45,0x1E,0x3F,0xA5,0x05,0x57,0x3D,0xE9,0x4D,0x69,0x3E,0xB1,0xA0,0x30,0x3D,0xE7,0x6B,0x38,0x3F,0xF6,0x20,0x74,0x3C,0xCC,0x21,0x4C,0x3E,0x63,0x0D,0x96,0x3C,0xA3,0xDB,0x54,0x3F,0xFA,0x26,0x13,0x3C,0x90,0xE6,0x0F,0x3E,0x90,0xCD,0x42,0x3C,0xDD,0xD7,0x1F,0x3F,0x4B,0xDA,0x30,0x3D,0xC5,0xEE,0x44,0x3E,0x22,0x34,0xEE,0x3C,0xE6,0xA0,0x61,0x3F,0xFE,0x65,0x7E,0x3F,0xF1,0xD9,0x70,0x3F,0xEF,0x7B,0x6F,0x3F,0x91,0x66,0x32,0x3E,0xDC,0xAF,0x5B,0x3F,0xE4,0x5E,0x64,0x3F,0xD0,0x57,0x50,0x3F,0xD6,0x88,0xC3,0x3E,0xA9,0x16,0x29,0x3E,0xED,0xC6,0x6C,0x3F,0xE4,0x92,0x23,0x3F,0x15,0x2A,0x9C,0x3E,0xF1,0xA5,0xF0,0x3E,0x90,0xF3,0x5B,0x3F,0x3F,0xF0,0x2C,0x3F,0x2E,0x97,0xD7,0x3E,0x22,0x0F,0x08,0x3F,0xD0,0x00,0xCF,0x3C,0x37,0x3A,0x56,0x3E,0x96,0x07,0xEA,0x3E,0x98,0x48,0xFD,0x3E,0x57,0x32,0xBC,0x3D,0xEE,0xC1,0x4D,0x3D,0xCA,0x94,0xC8,0x3E,
	0x2E,0x74,0xFA,0x3B,0x41,0xE2,0xA6,0x3D,0xB0,0xB4,0xAF,0x3D,0x04,0xFC,0x50,0x3D,0x9A,0x90,0x99,0x3D,0x84,0xE9,0x03,0x3E,0x61,0x87,0x7A,0x3D,0xB3,0x73,0x20,0x3E,0x1C,0x22,0x02,0x3D,0xE5,0xD3,0x64,0x3E,0x36,0x0A,0x9C,0x3C,0x82,0x9A,0x80,0x3E,0x81,0x82,0x66,0x3D,0x81,0xE4,0x80,0x3D,0xCE,0x6B,0x1A,0x3D,0xA6,0xA2,0x1F,0x3F,0x4D,0xEA,0x31,0x3D,0x9A,0x8B,0x19,0x3E,0x8F,0xC8,0x0E,0x3D,0xBB,0x7D,0x12,0x3F,0x5E,0x27,0x76,0x3D,0xFF,0xB3,0x7E,0x3E,0x29,0xAE,0x8F,0x3D,0x61,0x30,0x24,0x3F,0xAF,0x08,0xAE,0x3D,0xFC,0x18,0x7C,0x3E,0xC4,0x07,0x91,0x3D,0x5D,0xDD,0xA0,0x3E,0xF8,0xF8,0x77,0x3D,0x79,0x7D,0xAC,0x3D,0xFD,0x0E,0x16,0x3D,0xB6,0x65,0x69,0x3D,0x63,0x05,0x16,0x3D,0x0D,0x8B,0xA6,0x3D,0x18,0xE4,0xE4,0x3C,0xF4,0x7F,0xC0,0x3D,0xDE,0x6A,0x5E,0x3F,0xD1,0x2D,0x51,0x3F,0xD6,0x53,0x56,0x3F,0xFF,0xB0,0x80,0x3E,0xFB,0xE4,0x7A,0x3F,0xED,0x17,0x6D,0x3F,0xF1,0x34,0x71,0x3F,0x7D,0x3E,0x93,0x3E,0xD6,0xB0,0xD5,0x3E,0x87,0x3F,0x39,0x3F,0xB7,0x9A,0x22,0x3F,0xAA,0x3B,0xCB,0x3E,0xCE,0xAC,0xCD,0x3E,0x14,0xC4,0xDF,0x3E,0x8A,0xAD,0x24,0x3F,0xB4,0x62,0x91,0x3B,0xF6,0x3C,0x0F,0x3F,0x4B,0x06,0xB0,0x3D,0x3D,0x91,0x03,0x3D,0x48,0x67,0x60,0x3E,0xFA,0xD8,0xF9,0x3E,0x10,0x14,0x5B,0x3D,0xB9,0x42,0x3B,0x3D,0x6C,0xE0,0xAF,0x3E,0x15,0x4B,0xAE,0x3D,0x37,0xCA,0x9C,0x3D,0xF7,0x97,0xC3,0x3D,0x1B,0xDA,0x80,0x3B,
	0x80,0x0A,0xE5,0x3C,0x8E,0x80,0x0D,0x3D,0xB9,0x17,0x86,0x3D,0x11,0xEC,0xB9,0x3E,0x48,0x57,0xE0,0x3C,0xD7,0xE6,0x56,0x3E,0x6E,0x42,0x54,0x3D,0x65,0x7B,0xFC,0x3E,0xB7,0xF7,0x82,0x3D,0xCF,0xE4,0x4E,0x3E,0x00,0x57,0x99,0x3C,0xED,0x33,0x38,0x3E,0x4E,0x7D,0x81,0x3C,0x80,0x15,0x33,0x3D,0x73,0xD1,0xA5,0x3D,0xB6,0x28,0xB6,0x3D,0x74,0xBD,0xA6,0x3C,0xF9,0x32,0x92,0x3D,0xC3,0x63,0x0F,0x3D,0xFF,0x17,0xCC,0x3D,0x95,0x9D,0xC7,0x3D,0x1B,0xF6,0x80,0x3D,0x3E,0xA7,0xD7,0x3C,0xB6,0x45,0x69,0x3D,0xBB,0x40,0xBB,0x3D,0x1A,0x17,0xB3,0x3D,0x0F,0xF7,0xA7,0x3C,0x14,0x0C,0x61,0x3D,0x54,0x5D,0x87,0x3C,0x80,0x75,0xB3,0x3D,0xFE,0x06,0x17,0x3C,0x3D,0x67,0x56,0x3D,0xFD,0xCE,0x7C,0x3F,0xD2,0x83,0x51,0x3F,0xF2,0x80,0x71,0x3F,0x43,0xD1,0x85,0x3E,0xA5,0x54,0x25,0x3E,0xF6,0x82,0x75,0x3F,0xCE,0xD3,0x4D,0x3F,0xA6,0x75,0x88,0x3E,0xA9,0xB7,0xA8,0x3E,0xBA,0x07,0x39,0x3F,0xE1,0x9B,0xA6,0x3E,0x6A,0x35,0x76,0x3E,0x77,0xDF,0xA9,0x3E,0x04,0x1B,0x9D,0x3D,0x9F,0xB2,0x61,0x3D,0x25,0x1C,0x2C,0x3E,0x92,0x47,0x11,0x3F,0x59,0x8D,0x0B,0x3C,0x6F,0x73,0x99,0x3D,0x46,0x2F,0xBC,0x3E,0x1E,0xD8,0xE9,0x3E,0x8E,0xC9,0x0D,0x3E,0x71,0x36,0x02,0x3E,0x81,0xEC,0xC3,0x3E,0x1E,0x3F,0x36,0x3D,0xB5,0xFC,0x34,0x3D,0xCB,0x8F,0x97,0x3D,0x57,0x65,0x89,0x3D,0x3F,0xFA,0xA3,0x3C,0x9E,0x4D,0x1E,0x3E,0x82,0x55,0xB5,0x3D,0xC3,0x74,0xEF,0x3E,
	0x42,0xFA,0xA6,0x3D,0x9E,0x80,0x9D,0x3D,0xCD,0x98,0xCC,0x3D,0x3F,0x01,0x08,0x3E,0x58,0xBA,0xBD,0x3C,0x3F,0xE7,0x57,0x3D,0x68,0x21,0x9B,0x3D,0xC0,0x97,0x8C,0x3D,0xC7,0x60,0x46,0x3C,0x55,0xAD,0x07,0x3D,0x66,0x35,0x99,0x3D,0x9A,0xDD,0xCC,0x3C,0x95,0xB2,0x7A,0x3D,0x72,0xFA,0xD7,0x3C,0x20,0x2E,0x86,0x3D,0x3C,0xBA,0xA2,0x3C,0xAC,0xFC,0xAB,0x3D,0x24,0x47,0xBD,0x3C,0xF9,0x07,0xC6,0x3D,0xF3,0x2F,0xBF,0x3D,0x7F,0x12,0x65,0x3D,0xB6,0x2D,0x69,0x3C,0x85,0x99,0xB7,0x3D,0x72,0xD5,0x24,0x3D,0xDA,0xCF,0xA6,0x3D,0x1B,0xAE,0x81,0x3D,0x51,0xC1,0x83,0x3D,0x73,0x5A,0x59,0x3D,0xED,0x83,0x6C,0x3F,0xF3,0x5A,0x73,0x3F,0xD6,0x62,0x56,0x3F,0x0A,0x77,0xFC,0x3C,0x88,0x92,0x07,0x3F,0xEE,0xD3,0x6D,0x3F,0xF3,0xE8,0xF2,0x3E,0xCD,0x4F,0x51,0x3E,0xCC,0x38,0xCC,0x3E,0x26,0xE8,0x58,0x3F,0xBE,0xFB,0x26,0x3F,0x35,0x5E,0x83,0x3E,0x32,0xDB,0x17,0x3F,0xFA,0xBE,0x12,0x3D,0x94,0x5F,0x34,0x3E,0x6F,0x3A,0xBD,0x3E,0x94,0xB7,0x13,0x3F,0x8F,0x50,0x8E,0x3D,0xCD,0xF4,0xB7,0x3D,0x1D,0x91,0x57,0x3E,0x08,0x8B,0xA0,0x3D,0x94,0x06,0x14,0x3E,0x4C,0xFF,0x64,0x3D,0x55,0xFD,0x6C,0x3E,0xE3,0xB8,0x61,0x3D,0xA8,0x6A,0x28,0x3E,0xFE,0x93,0x4A,0x3D,0x94,0x07,0xC6,0x3E,0xAB,0x40,0xAA,0x3C,0xCE,0xAA,0x4D,0x3E,0x80,0x8D,0xB2,0x3C,0xF3,0x26,0x50,0x3E,0xD8,0xA0,0x57,0x3C,0xDD,0x80,0xDC,0x3B,0x4D,0xE7,0x65,0x3C,0x01,0x9F,0x9A,0x3D,
	0xBC,0x80,0x3B,0x3C,0xA8,0x78,0xA7,0x3D,0xF2,0x03,0x3F,0x3D,0xF8,0x0A,0x91,0x3D,0x56,0x7F,0x6F,0x3D,0x40,0xFE,0xA5,0x3D,0xC5,0xCB,0x91,0x3D,0xCC,0x4C,0xCC,0x3D,0xA6,0xFD,0x58,0x3D,0x73,0xDD,0xA5,0x3C,0x64,0x7E,0xCA,0x3D,0xFC,0x2B,0x48,0x3D,0x90,0x9A,0x76,0x3C,0xFB,0xC0,0x7A,0x3D,0x6E,0xCD,0x20,0x3A,0xB3,0xA8,0x32,0x3D,0x76,0x31,0xA9,0x3D,0x66,0x8D,0x18,0x3C,0x55,0x66,0xBB,0x3D,0xF2,0xB3,0xBE,0x3C,0x19,0xFC,0x65,0x3D,0xAC,0xC8,0xAB,0x3D,0x2F,0xE4,0xFB,0x3C,0x7F,0x21,0xB2,0x3D,0xFE,0x54,0x7E,0x3F,0xE3,0x84,0x62,0x3F,0xFC,0x1A,0x7C,0x3F,0x35,0x16,0x5D,0x3E,0x84,0x9B,0x03,0x3F,0xEC,0xC5,0x6B,0x3F,0xFB,0x3D,0x7B,0x3F,0x5A,0xF5,0xFC,0x3D,0xDD,0x8D,0xDC,0x3E,0x0A,0x46,0xD6,0x3E,0x82,0x90,0x5A,0x3E,0x04,0x8B,0x6B,0x3E,0x14,0xFB,0x2C,0x3E,0xF8,0x33,0xC3,0x38,0x2C,0x3A,0x1F,0x3E,0x4B,0xCC,0x19,0x3E,0xBC,0xC7,0xEE,0x3E,0x42,0xC6,0xA7,0x3D,0xD3,0x7E,0x9A,0x3D,0xE8,0x87,0x55,0x3E,0xBF,0xFD,0xF0,0x3C,0xE4,0x70,0xE4,0x3D,0x3E,0xC7,0x57,0x3C,0x03,0xBD,0xB1,0x3E,0x8A,0x40,0x89,0x3B,0xA0,0xC8,0x1F,0x3D,0x20,0xAE,0x86,0x3D,0x37,0xE8,0x3D,0x3E,0x99,0x65,0x4B,0x3D,0x85,0xA2,0x04,0x3E,0xCC,0x8D,0xFE,0x3C,0x90,0xCD,0xC1,0x3C,0x00,0x91,0xFF,0x3C,0x37,0x07,0xD0,0x3C,0x6F,0xEA,0x54,0x3D,0x54,0x8A,0xBA,0x3D,0x35,0xCE,0x9A,0x3D,0x5E,0x27,0x77,0x3D,0xCD,0x28,0x4D,0x3D,0xC6,0x1B,0x13,0x3D,
	0xB1,0x90,0x30,0x3D,0x9A,0xD8,0x99,0x3D,0xFC,0x6B,0xC8,0x3D,0x6D,0xD2,0x52,0x3D,0xB8,0x48,0x38,0x3D,0x22,0xE7,0xBB,0x3B,0x3C,0x76,0xA2,0x3D,0xF2,0x16,0x8B,0x3C,0x08,0xAB,0xA1,0x3D,0xD9,0xB7,0xA5,0x3D,0xCD,0x90,0xCC,0x3D,0xEC,0x13,0xB9,0x3C,0x74,0x71,0xA7,0x3D,0x24,0x2C,0x70,0x3D,0x65,0xB9,0x97,0x3D,0x97,0x74,0x96,0x3D,0x67,0x45,0x1A,0x3D,0xE9,0x86,0x02,0x3C,0x2B,0xC7,0xC4,0x3D,0x59,0xAD,0x0B,0x3C,0xFC,0xB9,0x7B,0x3F,0xF5,0x53,0x75,0x3F,0xF7,0x78,0x77,0x3F,0x6D,0xD5,0x4C,0x3D,0xFB,0xB0,0x7A,0x3D,0xED,0xC4,0x6C,0x3F,0xF9,0x23,0x79,0x3F,0xDE,0x33,0xA9,0x3D,0x96,0x87,0x95,0x3E,0xE6,0xB1,0x4B,0x3F,0xFB,0xF4,0xD0,0x3E,0xFE,0x67,0x05,0x3E,0x99,0xE8,0x18,0x3F,0xB2,0xB0,0xB0,0x3C,0x48,0x83,0x91,0x3D,0x1E,0xF6,0xC6,0x3D,0x81,0x7A,0xE6,0x3E,0x29,0x2C,0x74,0x3D,0x4F,0x34,0xE3,0x3D,0xDC,0x1E,0xFB,0x3D,0xE6,0xD3,0x31,0x3C,0xBC,0x1E,0xBC,0x3D,0x0E,0xF4,0xDA,0x3B,0x46,0x2F,0x0F,0x3E,0x91,0xED,0x42,0x3D,0xD7,0x86,0x56,0x3E,0xF1,0x6B,0x3D,0x3D,0x22,0x4E,0x4B,0x3E,0xE7,0x2A,0x80,0x3D,0xCB,0xF2,0x4A,0x3E,0x7A,0xD9,0xAC,0x3D,0x89,0x5F,0x18,0x3E,0x4E,0x15,0x01,0x3D,0x4F,0x3A,0xB5,0x3C,0x04,0xE7,0x9D,0x3B,0xC1,0x85,0x73,0x3D,0x03,0x13,0x9C,0x3D,0x96,0x80,0x15,0x3B,0xFF,0x73,0x4B,0x3C,0xCD,0x3B,0x99,0x3D,0xA3,0xAD,0xD5,0x3C,0x8C,0x90,0x0B,0x3D,0xEC,0x4F,0xB8,0x3D,0x62,0x1D,0x95,0x3C,
	0x2C,0xA2,0x92,0x3D,0xDB,0xDB,0x27,0x3D,0x97,0x54,0x97,0x3D,0x1D,0xC7,0x36,0x3D,0xB4,0x45,0x67,0x3D,0xFF,0xC6,0x18,0x3C,0x98,0xC0,0x17,0x3D,0x79,0x1D,0xAC,0x3C,0x28,0x87,0x41,0x3C,0x57,0x4A,0xBD,0x3D,0xFD,0x0A,0x96,0x3D,0xC1,0x8D,0x73,0x3C,0xC6,0xC0,0x45,0x3C,0x29,0x37,0xC2,0x3C,0x33,0x7B,0xCC,0x3D,0x90,0xD5,0xC2,0x3D,0xF8,0xA7,0x77,0x3F,0xE2,0x49,0x62,0x3F,0xDA,0xFF,0x59,0x3F,0x2F,0xB3,0x3C,0x3E,0xA6,0x23,0x26,0x3F,0xFB,0x39,0x7B,0x3F,0xBC,0x14,0xBC,0x3E,0xD7,0x75,0x0C,0x3E,0x81,0xA7,0x80,0x3E,0xEA,0x54,0x03,0x3E,0x18,0xAD,0x20,0x3F,0xF4,0x7A,0xE7,0x3D,0x61,0xC4,0xC6,0x3E,0x58,0x7A,0x3D,0x3C,0x9B,0x04,0x1D,0x3E,0xB5,0x85,0x2E,0x3E,0x2C,0x41,0x12,0x3F,0x21,0x97,0xB9,0x3C,0xA2,0x05,0x46,0x3D,0xE8,0x11,0xD6,0x3B,0x2E,0x9A,0x93,0x3B,0xE7,0x53,0x67,0x3E,0x11,0xC4,0xDD,0x3C,0x46,0x73,0x47,0x3D,0xDB,0x93,0x26,0x3C,0xA0,0x76,0xA0,0x3D,0xB3,0x60,0xB2,0x3C,0x47,0xDE,0xF0,0x3D,0x63,0xED,0x95,0x3C,0x56,0x35,0x09,0x3D,0xB9,0x4D,0xEC,0x3C,0xC4,0x37,0x90,0x3D,0x05,0x67,0x1E,0x3A,0x44,0x82,0xAA,0x3D,0xBF,0x3B,0x8B,0x3D,0x8C,0xD4,0x8B,0x3D,0xCD,0x13,0x9A,0x3C,0x94,0x8D,0xC6,0x3C,0x23,0xB2,0x09,0x3D,0x48,0x3E,0xAE,0x3D,0x24,0xF6,0x89,0x3D,0x5D,0x8D,0x90,0x3D,0x3B,0x6A,0x21,0x3D,0xC4,0x25,0x77,0x3D,0xCB,0xFD,0xFD,0x3C,0xBC,0xCD,0xEE,0x3B,0xB2,0x0D,0x65,0x3D,0x5D,0x67,0xF6,0x3C,
	0xA9,0xBD,0x5B,0x3D,0xC2,0x7D,0x74,0x3D,0x99,0x9A,0x7F,0x3D,0x99,0xA0,0x98,0x3D,0x86,0x79,0xB9,0x3D,0x6C,0x2D,0x9F,0x3D,0x53,0x26,0xB9,0x3D,0xB6,0xD8,0xB5,0x3D,0xD6,0x8B,0xA2,0x3D,0x29,0xD4,0x75,0x3D,0xDB,0x10,0x5B,0x3D,0x47,0x87,0x60,0x3C,0xF6,0x14,0x76,0x3F,0xF5,0xEC,0x74,0x3F,0xEF,0x60,0x6F,0x3F,0x59,0x47,0xF0,0x3C,0xA8,0xA8,0xA7,0x3E,0xFF,0x00,0x7F,0x3F,0x81,0xB0,0x00,0x3F,0x26,0x6E,0xA1,0x3C,0x83,0x9E,0x82,0x3E,0x97,0x0D,0x63,0x3F,0x93,0xDA,0xD7,0x3E,0xEF,0xB6,0x61,0x3C,0x2A,0xC8,0x0F,0x3F,0xDF,0xA3,0xAA,0x3D,0x53,0xB5,0x55,0x3C,0xE9,0x00,0xE7,0x3C,0x30,0x87,0x49,0x3E,0x58,0x29,0x8A,0x3D,0x34,0xC6,0x64,0x3D,0xCE,0x3D,0x25,0x3D,0x9B,0x6C,0x9A,0x3D,0x8D,0x00,0x0D,0x3C,0xEA,0x92,0x83,0x3D,0xC2,0x54,0x57,0x3C,0xE9,0xF3,0xB4,0x3D,0xD0,0x90,0x4F,0x3C,0xC3,0xF3,0x8F,0x3D,0x58,0x67,0x6F,0x3B,0x3C,0xFA,0x20,0x3C,0xE9,0x26,0x69,0x3E,0x5A,0x4D,0x0D,0x3B,0x32,0xBE,0x95,0x3D,0x8D,0x6D,0x40,0x3D,0x3C,0x67,0x55,0x3C,0xD4,0xFF,0xA0,0x3D,0xA4,0xA8,0x23,0x3D,0xDB,0x33,0xA7,0x3C,0x46,0x8A,0x2C,0x3D,0xA4,0xAD,0xD6,0x3C,0xB4,0x3B,0x00,0x3D,0xF5,0x43,0x41,0x3D,0x68,0xAD,0x9A,0x3C,0xCB,0x63,0x97,0x3C,0x40,0x4A,0xA6,0x3D,0x90,0xC1,0xC2,0x3D,0xC8,0xE0,0x47,0x3C,0x7A,0xBA,0x5F,0x3D,0x5C,0x6E,0xC2,0x3D,0x2A,0xA3,0xC3,0x3D,0x01,0x2C,0x4D,0x3D,0xB2,0x25,0x65,0x3D,0x69,0x8D,0x9B,0x3D,
	0x73,0x4D,0x26,0x3C,0x70,0xD1,0xA2,0x3D,0xAF,0xEC,0xAE,0x3D,0xF2,0x4F,0xBE,0x3D,0xE6,0xF0,0x65,0x3D,0x33,0xE2,0x18,0x3D,0xF5,0x16,0x0E,0x3D,0x01,0x8B,0x9A,0x3D,0xFC,0x48,0x7C,0x3F,0xE3,0xEC,0x62,0x3F,0xF7,0xEB,0x76,0x3F,0x9C,0xCD,0xCD,0x3B,0xA2,0xCA,0x21,0x3F,0xB9,0xAB,0x38,0x3F,0xE5,0x13,0x65,0x3F,0xD7,0x80,0xD5,0x3B,0xD2,0x92,0x51,0x3E,0xA6,0x6E,0x58,0x3F,0x4C,0x6D,0x5F,0x3E,0x9C,0x88,0x19,0x3D,0xF6,0x63,0x0F,0x3F,0x14,0x47,0x2C,0x3C,0x03,0xB9,0xDF,0x3D,0xE0,0x0B,0x2A,0x3D,0x5F,0x4B,0x12,0x3F,0x8C,0x70,0x8B,0x3C,0x51,0xBF,0x5B,0x3D,0xF6,0xE8,0x71,0x3D,0xA9,0x94,0xA7,0x3D,0xB7,0x20,0x37,0x3D,0xEC,0x3F,0xB8,0x3D,0x56,0xEF,0x6B,0x3D,0xEF,0xC0,0x6D,0x3C,0x8E,0x80,0x8D,0x3A,0x50,0x61,0x83,0x3D,0x00,0xBC,0x49,0x3D,0xF4,0x5B,0xBF,0x3D,0xEE,0xF8,0x6D,0x3E,0x48,0xCA,0x2D,0x3D,0xBB,0x5D,0x6A,0x3D,0x87,0xDD,0x39,0x3D,0x19,0x83,0xB2,0x3D,0xEA,0x53,0x36,0x3D,0x86,0xA8,0x05,0x3D,0x18,0x14,0x64,0x3C,0x24,0x2A,0x0A,0x3D,0x03,0xE7,0x9C,0x3C,0xD1,0x10,0xD1,0x3C,0x5F,0xC2,0xC4,0x3D,0x74,0xBD,0xA6,0x3D,0x75,0xFA,0x5A,0x3D,0xBC,0x10,0xBC,0x3C,0x00,0x13,0x99,0x3D,0x9C,0xCD,0x4E,0x3A,0xAD,0x30,0xAD,0x3C,0xF3,0xE6,0x0C,0x3B,0x1A,0x5A,0x00,0x3C,0xF8,0xA0,0xF7,0x3C,0x26,0xC7,0xBF,0x3D,0x7C,0x61,0xAF,0x3D,0xB6,0xA0,0x35,0x3C,0x92,0x48,0x12,0x3D,0x64,0x6A,0xCA,0x3D,0xB7,0xD8,0x36,0x3D,
	0xC7,0x40,0xC7,0x3C,0x2F,0xEF,0x47,0x3D,0xA3,0xC8,0xA2,0x3D,0x4E,0xF1,0x80,0x3D
},

/* input data and other run-time fields*/

{0}

}; /* done */
