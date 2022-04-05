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
	{triangular,0.062392f,0,0.121510f,0.121510f},{triangular,0.192771f,0,0.132404f,0.132404f},{triangular,0.298838f,0,0.074163f,0.074163f},{triangular,0.373709f,0,0.071649f,0.071649f},{triangular,0.448150f,0,0.073325f,0.073325f},{triangular,0.516781f,0,0.060336f,0.060336f},{triangular,0.589071f,0,0.080448f,0.080448f},{triangular,0.655551f,0,0.049023f,0.049023f},{triangular,0.702237f,0,0.041900f,0.041900f},{triangular,0.745912f,0,0.043157f,0.043157f},{triangular,0.795611f,0,0.053632f,0.053632f},{triangular,0.848322f,0,0.049023f,0.049023f},{triangular,0.896730f,0,0.045252f,0.045252f},{triangular,0.938683f,0,0.036453f,0.036453f},{triangular,0.978701f,0,0.041481f,0.041481f},
	{descending,0.023512f,0,0,0.115452f},{triangular,0.170430f,0,0.178088f,0.095812f},{triangular,0.254915f,0,0.072987f,0.104305f},{triangular,0.359857f,0,0.105367f,0.050693f},{triangular,0.435707f,0,0.100855f,0.071129f},{triangular,0.531615f,0,0.120495f,0.070598f},{triangular,0.578108f,0,0.022294f,0.020171f},{triangular,0.598565f,0,0.020702f,0.031318f},{triangular,0.625399f,0,0.022294f,0.046712f},{triangular,0.677471f,0,0.057328f,0.049897f},{triangular,0.725027f,0,0.045119f,0.050427f},{triangular,0.776036f,0,0.051489f,0.033441f},{triangular,0.824389f,0,0.063167f,0.070598f},{triangular,0.886504f,0,0.053506f,0.053719f},{ascending,0.954152f,0,0.081442f,0}
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
	0xAF,0x18,0x2F,0x3E,0xDE,0xE0,0x5D,0x3D,0xD0,0x67,0x50,0x3F,0xF3,0x51,0x73,0x3F,0xEF,0x5E,0xEF,0x3E,0xE8,0x9F,0x67,0x3F,0xF8,0xC4,0xF7,0x3E,0xFE,0x4A,0x7E,0x3F,0xD5,0x48,0xD5,0x3D,0x9E,0x4A,0x9E,0x3E,0xC8,0xEC,0x47,0x3E,0xAE,0x60,0xAE,0x3C,0xDD,0xEF,0x5C,0x3F,0x81,0x02,0x01,0x3F,0x98,0x74,0x18,0x3E,0xE7,0x70,0x67,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xA1,0x85,0x2C,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xC2,0x66,0x49,0x3F,0xC1,0x69,0x41,0x3F,0xB1,0x90,0xB0,0x3E,0xCB,0x00,0xCB,0x3D,0xE3,0xC7,0x62,0x3F,0x41,0x78,0x7F,0x3F,0x00,0x00,0x80,0x3F,0x2D,0x8B,0x7F,0x3F,0x8F,0xD0,0x5A,0x3F,0x00,0x00,0x80,0x3F,0x8A,0xFF,0x7F,0x3F,0x00,0x00,0x80,0x3F,0x2E,0x72,0x52,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x36,0x32,0x65,0x3F,0xF5,0x62,0x7F,0x3F,0x4A,0xAC,0x60,0x3F,0xE7,0x44,0x6A,0x3F,0x76,0x0E,0x63,0x3F,0xF1,0x50,0x7F,0x3F,0xA8,0x33,0x54,0x3F,0x4E,0x19,0x62,0x3F,0x1E,0x8E,0x6F,0x3F,0xFD,0xFF,0x7F,0x3F,0xED,0xFE,0x7F,0x3F,0x49,0xFF,0x7F,0x3F,0xA8,0x8B,0x7D,0x3F,0x82,0xF1,0x7F,0x3F,0x1D,0x14,0x3B,0x3F,0x70,0x0B,0x63,0x3F,0x00,0x00,0x80,0x3F,0xE7,0xF2,0xBB,0x3E,0x02,0xD3,0x33,0x3F,0x7C,0x05,0xC9,0x3E,0x00,0x00,0x80,0x3F,0xD0,0xD2,0x4F,0x3F,0x87,0x80,0x06,0x3F,0x9A,0x21,0x1A,0x3F,0xA5,0x9C,0x24,0x3F,
	0xFC,0xBC,0x7B,0x3E,0xB8,0xBB,0x37,0x3F,0xCC,0x90,0x4B,0x3E,0x82,0x3E,0x82,0x3E,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x15,0xBA,0x24,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x11,0xEF,0x1A,0x3F,0xA8,0xFD,0x7F,0x3F,0x56,0xFD,0x7F,0x3F,0xD2,0xFD,0x7F,0x3F,0x66,0xCF,0x46,0x3F,0xB6,0x4F,0x49,0x3F,0x5C,0x58,0x55,0x3F,0xB5,0x0D,0x4D,0x3F,0x48,0xC6,0x28,0x3F,0xF1,0x00,0xF1,0x3B,0x93,0x60,0x13,0x3F,0x9E,0x76,0x1E,0x3F,0xA1,0x0B,0x21,0x3F,0xA1,0x22,0xEC,0x3E,0x01,0x03,0x3E,0x3F,0x91,0x96,0x14,0x3F,0x73,0x29,0x2C,0x3F,0xC9,0xD7,0x46,0x3F,0xEE,0x6C,0xCE,0x3E,0xE3,0x3C,0xD4,0x3E,0x5A,0xD4,0x48,0x3F,0xFA,0x02,0x9D,0x3E,0xF0,0xFF,0x7F,0x3F,0x7C,0x44,0x5C,0x3F,0xD6,0x4B,0x3E,0x3F,0x23,0x0C,0xFF,0x3E,0xBE,0xF8,0x66,0x3F,0xE8,0xFD,0x1B,0x3F,0x1B,0x34,0x49,0x3F,0xDD,0xFB,0x4B,0x3E,0x0E,0xF5,0x99,0x3E,0xB1,0x1D,0x82,0x3D,0x61,0xB6,0x58,0x3F,0xCF,0x71,0x0A,0x3F,0xED,0xFE,0x7F,0x3F,0xF1,0x30,0x6A,0x3F,0x93,0x66,0x66,0x3F,0x4E,0xC4,0x85,0x3E,0xD8,0x66,0x3C,0x3F,0xF1,0x1B,0xF4,0x3E,0xB7,0x73,0x78,0x3F,0x70,0x60,0xB3,0x3E,0x18,0xD7,0x3B,0x3F,0x04,0xAD,0x1D,0x3F,0x00,0x00,0x80,0x3F,0x97,0x14,0x17,0x3E,0xBB,0xE0,0xBA,0x3C,0x9F,0xAC,0x1E,0x3F,0xF0,0xC6,0x6F,0x3F,0x5A,0x4F,0x7C,0x3F,0xF8,0x72,0x75,0x3F,0x00,0x00,0x80,0x3F,0x43,0xBB,0x1C,0x3F,
	0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x61,0x4B,0x1B,0x3F,0x9E,0xAB,0x75,0x3F,0xC1,0xD4,0x74,0x3F,0x2C,0xD2,0x7B,0x3F,0xE6,0xDE,0x0F,0x3F,0xA8,0xFD,0x7F,0x3F,0x49,0xAC,0x2F,0x3E,0x90,0x14,0xC7,0x3E,0x37,0x36,0x1C,0x3F,0xAE,0x90,0x0E,0x3F,0xC6,0xDE,0xB0,0x3E,0x39,0x4B,0x89,0x3E,0xD2,0x2E,0x27,0x3F,0x98,0x8A,0x97,0x3E,0xAF,0x00,0x2F,0x3E,0xAA,0x78,0xAA,0x3D,0x8B,0x65,0x0B,0x3F,0xE8,0x9B,0xB6,0x3E,0x53,0xAE,0x56,0x3F,0x5B,0xC5,0x23,0x3F,0x13,0xBE,0x3D,0x3F,0x9E,0xB7,0xDB,0x3E,0xA3,0x86,0x6A,0x3F,0x01,0x54,0x37,0x3F,0x9E,0x8F,0x4E,0x3F,0xE8,0x4D,0xD7,0x3E,0x88,0x34,0x35,0x3F,0xC6,0xC5,0x04,0x3F,0x2C,0x48,0x4A,0x3F,0x2D,0xFE,0xB8,0x3E,0x00,0x00,0x80,0x3F,0x93,0x67,0x51,0x3F,0xC4,0xB3,0x49,0x3F,0xF3,0x26,0xC6,0x3E,0xEB,0xD3,0xCB,0x3E,0x57,0x6A,0x25,0x3F,0x55,0xFF,0x7F,0x3F,0x97,0xCE,0xF1,0x3E,0x0D,0x9F,0x48,0x38,0x22,0x3E,0xE1,0x3D,0xF0,0xFF,0x7F,0x3F,0x25,0xDF,0x19,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xFC,0x67,0x3F,0x81,0xE9,0x0E,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x67,0x7F,0x3F,0x1D,0xF3,0x69,0x3F,0x8D,0x26,0x7A,0x3F,0x36,0x7A,0x74,0x3F,0x12,0xF8,0x09,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xFB,0xBD,0x02,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x02,0xDC,0x04,0x3F,
	0x1C,0x47,0x7A,0x3F,0xCF,0x29,0x73,0x3F,0x87,0xEA,0x6F,0x3F,0xD7,0x2D,0xF1,0x3E,0xF5,0xE1,0x10,0x3F,0x34,0x58,0x24,0x3F,0xD6,0xE8,0xF2,0x3E,0x4A,0x85,0x08,0x3F,0x4A,0x0D,0x97,0x3E,0xE5,0xFE,0x7F,0x3F,0x94,0x7B,0x4A,0x3F,0xED,0x12,0x2D,0x3F,0x29,0x70,0x11,0x3F,0x67,0x13,0xAB,0x3D,0x3B,0x83,0x2D,0x3E,0xBF,0x5E,0x09,0x3F,0xEC,0x62,0x08,0x3F,0x82,0xC1,0xE7,0x3E,0x6D,0x75,0xDB,0x3D,0xB3,0x68,0x2C,0x3F,0xEB,0xFA,0x31,0x3F,0x00,0x00,0x00,0x00,0x56,0x2B,0xD3,0x3D,0x9C,0xCB,0x34,0x3F,0xC3,0x0A,0x0E,0x3F,0x00,0x00,0x00,0x00,0xCA,0x20,0xD9,0x3D,0x45,0xBA,0x40,0x3F,0x06,0x0A,0x04,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEA,0x69,0x47,0x3F,0x64,0x12,0x11,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x35,0xD8,0xF3,0x3E,0x6D,0x19,0x0A,0x3F,0x00,0x00,0x00,0x00,0x63,0xF3,0x3C,0x38,0x00,0x00,0x80,0x3F,0x31,0xFB,0xD8,0x3E,0x00,0x00,0x00,0x00,0xEB,0x38,0xF2,0x3D,0xA2,0x70,0xAF,0x3E,0x33,0x04,0x2B,0x3B,0xA0,0x14,0x0C,0x3E,0x8A,0xA8,0x26,0x3A,0xEC,0x6B,0x79,0x3F,0xCF,0x31,0x5D,0x3F,0xD0,0x77,0x72,0x3F,0xF3,0xD8,0x5B,0x3F,0x4A,0xBF,0x11,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xA6,0x9C,0xDC,0x3E,0x79,0xDC,0x04,0x3F,0x00,0x00,0x80,0x3F,0x4D,0xF9,0xAE,0x3E,0xAA,0x12,0x25,0x3F,0xD7,0x9D,0x8D,0x3E,0x00,0x00,0x80,0x3F,0xE1,0x28,0x4D,0x3F,0xA4,0xD2,0xDF,0x3E,
	0xB3,0x50,0xB9,0x3E,0x00,0x00,0x80,0x3F,0xC0,0xCB,0x4D,0x3F,0x63,0x52,0x04,0x3F,0x11,0x09,0xF8,0x3E,0xBC,0x43,0x0F,0x3D,0x9D,0xDA,0xDA,0x3D,0x9F,0x34,0x1D,0x3F,0x1F,0x20,0x32,0x3F,0x00,0x00,0x00,0x00,0x01,0x8A,0xA4,0x3D,0x9B,0x09,0xFA,0x3E,0xF4,0x07,0xC8,0x3E,0x00,0x00,0x00,0x00,0x4B,0xD7,0xD7,0x3D,0x6E,0x93,0x2E,0x3F,0x10,0xB9,0x81,0x3E,0x00,0x00,0x00,0x00,0x9F,0x28,0xE0,0x3D,0x9A,0xAD,0x1A,0x3F,0xD3,0xF3,0x8D,0x3D,0x59,0x1E,0x94,0x2C,0x1F,0x0C,0x6F,0x3D,0xC8,0xCC,0xF6,0x3E,0x70,0xCD,0xA2,0x3B,0xF3,0x1B,0xC0,0x3D,0x07,0xF4,0xD3,0x3B,0x90,0x68,0x8F,0x3D,0x68,0x6D,0x51,0x32,0xA8,0x9A,0x79,0x3D,0x51,0x98,0xB1,0x3C,0x57,0x2A,0x2D,0x3F,0xB6,0x66,0x36,0x2D,0x97,0xBC,0x32,0x3E,0x00,0x00,0x00,0x00,0x26,0xA5,0xD7,0x3E,0xB0,0x87,0x0B,0x2D,0xA6,0x63,0x31,0x3E,0x00,0x00,0x00,0x00,0xC9,0xD4,0x79,0x3F,0x00,0x00,0x00,0x00,0x5E,0x3A,0x20,0x3E,0x00,0x00,0x00,0x00,0xDC,0xFD,0x7D,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xB3,0x96,0xD9,0x3E,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xC0,0x46,0x4E,0x3E,0x8B,0x5B,0x6C,0x3E,0x00,0x00,0x80,0x3F,0xAF,0x70,0x7E,0x3F,0x2C,0x53,0x2D,0x3E,0x40,0x34,0xCD,0x3E,0x35,0xCF,0x68,0x3F,0x60,0x23,0x20,0x3F,0x43,0x0F,0x0F,0x3F,0x36,0x93,0xF3,0x3E,0xA7,0x24,0xCB,0x3E,0x75,0xA2,0xA2,0x3E,0x65,0x4B,0xEE,0x3E,
	0x18,0xAA,0x01,0x3F,0x00,0x00,0x00,0x00,0xDD,0xE8,0xDF,0x3D,0x3B,0x76,0xFC,0x3E,0x03,0x2B,0x9C,0x3D,0x93,0x64,0x92,0x3D,0x55,0xAD,0x87,0x3C,0x6D,0x22,0x53,0x3D,0xFB,0xAB,0x47,0x3D,0xD4,0x88,0x53,0x3D,0x27,0x57,0xC0,0x3D,0xA4,0xC5,0x56,0x3D,0xCB,0x3C,0xCB,0x3D,0xA2,0x20,0xA2,0x3C,0xB7,0x80,0x36,0x3C,0xF1,0x12,0x8A,0x3D,0xC4,0x7B,0x90,0x3D,0xC5,0xF3,0x11,0x3D,0x75,0xB1,0xA7,0x3D,0xDA,0x90,0xD9,0x3C,0xCC,0x6A,0xE1,0x3A,0x68,0xEE,0x69,0x3E,0x50,0xBD,0x0C,0x3C,0xAA,0xEC,0xC5,0x3E,0x00,0x00,0x00,0x00,0xA9,0x11,0x16,0x3E,0x00,0x00,0x00,0x00,0xFD,0xE1,0x40,0x3F,0x00,0x00,0x00,0x00,0x7C,0x86,0x30,0x3E,0x00,0x00,0x00,0x00,0x05,0x71,0x6D,0x3F,0xB9,0x54,0x21,0x2D,0x91,0x80,0xDB,0x3D,0x00,0x00,0x00,0x00,0x93,0xEE,0x2E,0x3F,0x7E,0xEF,0xAE,0x3B,0xCE,0xF0,0xFF,0x3D,0x17,0x30,0x1A,0x3C,0xDD,0x04,0x24,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x88,0x87,0xC0,0x3E,0x52,0xBE,0x3D,0x3F,0x00,0x00,0x80,0x3F,0xD1,0xF9,0x54,0x3F,0x8B,0xAA,0x89,0x3E,0x2D,0x07,0x0A,0x3E,0xD8,0x6D,0x7A,0x3F,0x6F,0x6E,0x1F,0x3F,0x65,0xA6,0xC5,0x3E,0xDB,0xFE,0x3A,0x3F,0x44,0x5D,0x00,0x3F,0x9E,0x01,0xFA,0x3E,0x90,0xF4,0xCC,0x3E,0x56,0xC3,0x08,0x3F,0x00,0x00,0x00,0x00,0x52,0xB4,0x01,0x3E,0x2A,0x83,0xC6,0x3E,0xFA,0xDE,0xF4,0x3E,0x00,0x00,0x00,0x00,0x2D,0xE4,0xB2,0x36,0x9A,0x0C,0xFF,0x3E,
	0xB3,0x90,0xB2,0x3D,0x98,0xD1,0xCA,0x3D,0x7A,0x15,0xAD,0x3D,0xFB,0x40,0x7B,0x3C,0x5F,0x15,0x6E,0x3D,0xFB,0x9B,0x1D,0x3D,0xA7,0xF1,0x2D,0x3C,0xEA,0xC6,0x88,0x3D,0xF8,0x66,0xD4,0x3C,0xAF,0x1F,0x43,0x3D,0xEC,0xB0,0xCE,0x3C,0x93,0x64,0x13,0x3F,0x00,0x00,0x00,0x00,0xD6,0x2F,0x38,0x3E,0x00,0x00,0x00,0x00,0x5E,0xE6,0xF1,0x3E,0x18,0x26,0x86,0x2D,0xEA,0xEF,0xF2,0x3D,0x00,0x00,0x00,0x00,0x01,0x5F,0x2F,0x3F,0x6C,0x9C,0xC5,0x3B,0x93,0xEA,0x09,0x3E,0x0E,0x35,0x44,0x3B,0x59,0x19,0xF9,0x3E,0x00,0x00,0x00,0x00,0xE5,0x63,0x31,0x3E,0x00,0x00,0x00,0x00,0x85,0xE4,0x92,0x3E,0x1C,0x9A,0x82,0x3A,0x31,0xFE,0x96,0x3D,0x85,0xA1,0xB7,0x3D,0xD0,0xA0,0x4F,0x3C,0xBF,0x80,0x3E,0x3B,0x69,0x12,0x4F,0x3D,0x18,0xE7,0xB1,0x3D,0xA9,0x58,0xA8,0x3D,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x3B,0x1D,0x87,0x3E,0x5D,0x50,0x64,0x3F,0x07,0x90,0x7E,0x3F,0xA6,0x8F,0x7D,0x3F,0xAF,0x6D,0x2E,0x3E,0x9F,0xF9,0xC7,0x3E,0x68,0x18,0x3F,0x3F,0x75,0x5C,0x47,0x3F,0x66,0xDF,0xAF,0x3E,0x5C,0x8B,0x02,0x3F,0x07,0x21,0x66,0x3F,0xA9,0xD1,0x93,0x3E,0xD6,0xE6,0x18,0x3E,0x4C,0x9D,0xC5,0x3E,0xA7,0x35,0x29,0x2D,0xC0,0xAA,0xE7,0x3D,0xDD,0x32,0xDD,0x3E,0xA5,0xBC,0x16,0x3F,0xC0,0x80,0xE9,0x2C,0x3A,0x3A,0xE4,0x3D,0xFB,0x64,0x3A,0x3E,0x52,0x95,0x84,0x3D,0xB2,0xCD,0xE4,0x3C,0xD9,0x48,0x59,0x3D,0xC8,0xFD,0x7A,0x3D,
	0x00,0x00,0x00,0x00,0xB7,0x06,0x34,0x3D,0x00,0x00,0x00,0x00,0x86,0x80,0x01,0x3F,0x00,0x00,0x00,0x00,0xF6,0xA7,0x41,0x3E,0x00,0x00,0x00,0x00,0x24,0x97,0xD8,0x3E,0x00,0x00,0x00,0x00,0xE8,0xD8,0xAD,0x3D,0x00,0x00,0x00,0x00,0x68,0x5A,0x0C,0x3F,0xE2,0x0B,0xAF,0x3D,0x53,0x82,0xB9,0x3D,0x17,0x63,0xB0,0x3D,0xBF,0x7C,0xBE,0x3D,0x38,0x3A,0x9E,0x3D,0x23,0xD4,0x6F,0x3D,0xCC,0x23,0x99,0x3D,0xED,0x6B,0x39,0x3D,0x88,0xBD,0xBA,0x3D,0x9D,0xD0,0x9C,0x3D,0xF9,0x97,0xC5,0x3D,0x5B,0x5E,0xC1,0x3D,0x16,0xA4,0x62,0x3D,0x39,0x32,0x1F,0x3D,0xC2,0xA0,0xC1,0x3D,0x31,0x9F,0x4A,0x3D,0xD5,0xF0,0x54,0x3D,0x77,0x71,0xAA,0x3D,0xCB,0xA3,0x17,0x3D,0xE3,0x67,0xAF,0x3D,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x52,0xE1,0x73,0x3E,0x57,0xA0,0x19,0x3F,0xAC,0xFF,0x7F,0x3F,0xFD,0x37,0x78,0x3F,0x22,0x7C,0x7B,0x3E,0x31,0xA7,0xF4,0x3D,0xE2,0x2B,0x24,0x3F,0xBB,0x33,0x60,0x3E,0x15,0x94,0xA0,0x3E,0x51,0x8F,0xF0,0x3E,0x20,0x0F,0xD6,0x3A,0xBF,0x29,0xD8,0x3D,0x15,0xA0,0xB8,0x3E,0x0A,0x4C,0x2B,0x3F,0x00,0x00,0x00,0x00,0xB6,0xA1,0x8F,0x3D,0xF3,0x1D,0x86,0x3E,0x02,0x72,0xDD,0x3E,0xDA,0xDC,0x6E,0x3D,0xB3,0x80,0x1A,0x3E,0x11,0x2E,0xA2,0x3E,0x00,0x00,0x00,0x00,0x69,0x5E,0x09,0x3E,0x00,0x00,0x00,0x00,0x0A,0x9E,0x8A,0x3E,0x00,0x00,0x00,0x00,0x73,0x45,0x53,0x3E,0x00,0x00,0x00,0x00,0x0F,0xEA,0xCF,0x3E,
	0x54,0x72,0x75,0x3C,0x1E,0x21,0x0E,0x3E,0x06,0x47,0xB3,0x3C,0x85,0x7E,0x27,0x3E,0x88,0x25,0xBB,0x3D,0xB8,0x00,0x38,0x39,0x11,0xBC,0x5D,0x3D,0x02,0x9B,0x9B,0x3D,0x33,0xC3,0xCC,0x3D,0xC4,0x33,0x90,0x3A,0x00,0xBC,0xCC,0x3D,0x52,0x0D,0x85,0x3D,0x4A,0x82,0xB0,0x3D,0xB6,0xE3,0x02,0x3D,0xA8,0xCD,0x5A,0x3B,0xCA,0xDC,0xC9,0x3D,0x64,0x55,0x17,0x3D,0x58,0xFA,0xBD,0x3C,0xF1,0xF3,0x3D,0x3D,0xDB,0xC0,0xDA,0x3B,0x61,0x0D,0x14,0x3C,0x1F,0xCA,0x84,0x3D,0xFB,0xEB,0x47,0x3D,0x98,0x50,0x98,0x3D,0x2D,0x67,0xC6,0x3C,0xFA,0x7F,0xC6,0x3D,0xB6,0x0B,0x03,0x3D,0xF3,0x60,0xF2,0x3C,0x00,0x00,0x80,0x3F,0xDE,0x94,0x47,0x3F,0x89,0x14,0x46,0x3F,0x7B,0x77,0xC1,0x3D,0xB4,0x11,0xB5,0x3E,0xCC,0xFF,0x7F,0x3F,0xCB,0x97,0x2C,0x3F,0xEB,0xE4,0x60,0x3E,0x92,0x44,0xB0,0x3E,0x99,0x21,0x2B,0x3F,0x89,0xB8,0x0D,0x3F,0x63,0x8A,0x68,0x3E,0x0C,0x0C,0xDB,0x3E,0x00,0x00,0x00,0x00,0x8F,0x03,0xDF,0x3D,0x11,0xB0,0xD4,0x3E,0x96,0x2D,0xDA,0x3E,0x00,0x00,0x00,0x00,0x75,0x0F,0xFB,0x3D,0x31,0x2F,0x39,0x3D,0x00,0x00,0x00,0x00,0xE2,0x82,0x88,0x3E,0x00,0x00,0x00,0x00,0x5A,0x0E,0x07,0x3E,0x00,0x00,0x00,0x00,0x35,0xBE,0x10,0x3E,0x00,0x00,0x00,0x00,0x89,0x8B,0xC9,0x3E,0x00,0x00,0x00,0x00,0x60,0xD2,0xD6,0x3D,0x00,0x00,0x00,0x00,0xD5,0x11,0xA4,0x3E,0x81,0x50,0x81,0x3C,0xD3,0x67,0x9F,0x3D,0x42,0x2E,0xA8,0x3D,0xA7,0x00,0x27,0x3C,
	0x93,0x6C,0x92,0x3D,0x90,0x8D,0xC2,0x3C,0x5C,0x07,0xF5,0x3C,0xE8,0xFB,0xB4,0x3D,0x17,0x14,0x63,0x3D,0xC6,0x3D,0x79,0x3D,0x23,0xFA,0x88,0x3D,0x3F,0x5A,0x25,0x3D,0x69,0xB5,0x9B,0x3D,0xB8,0x28,0x38,0x3D,0x73,0xCD,0xA5,0x3B,0xC9,0x9B,0x15,0x3D,0xD6,0xCF,0xA2,0x3D,0xF6,0xE7,0xC2,0x3D,0x9D,0x5C,0x9C,0x3D,0xDD,0x30,0x5D,0x3D,0x29,0x9E,0x8F,0x3D,0xD2,0x93,0x9E,0x3D,0x9C,0x18,0x9C,0x3D,0xF6,0xA7,0xC2,0x3D,0x7D,0x51,0xB0,0x3D,0xF1,0xF7,0xBD,0x3D,0xF8,0x5B,0xC4,0x3D,0x95,0x25,0x48,0x3D,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x93,0xBE,0x24,0x3E,0x0A,0x0B,0x49,0x3F,0x5A,0xAC,0x4E,0x3F,0x4C,0x23,0x73,0x3F,0x1F,0x0F,0x86,0x3E,0xA3,0x16,0xAA,0x3E,0xF6,0xED,0x7F,0x3F,0xD4,0x3E,0xDF,0x3E,0xA2,0x57,0x2A,0x3E,0x27,0x9D,0x1C,0x3F,0x09,0xB5,0x10,0x2D,0xF1,0xBE,0x08,0x3E,0x18,0x0B,0x97,0x3E,0x56,0xA1,0x09,0x3F,0x13,0x47,0x62,0x2D,0x28,0x67,0x8C,0x3D,0x5C,0x42,0x2B,0x3E,0xFE,0x8F,0xD6,0x2B,0x9B,0x2F,0x54,0x3E,0x00,0x00,0x00,0x00,0xB2,0xF6,0xAD,0x3E,0xFE,0x8F,0xD6,0x2B,0x9F,0x84,0x03,0x3E,0x00,0x00,0x00,0x00,0x0E,0x62,0x46,0x3E,0xAD,0x39,0x06,0x3D,0x92,0xD2,0xF5,0x3D,0xD8,0x61,0xCE,0x3B,0x60,0xB8,0x27,0x3E,0xEE,0xC0,0xED,0x3C,0xE7,0x38,0x67,0x3D,0x2A,0x34,0x76,0x3C,0x7C,0xED,0x2E,0x3D,0xED,0xF3,0xB9,0x3C,0xFD,0x3B,0x49,0x3D,0xEB,0xBE,0x84,0x3D,0x18,0x37,0xB1,0x3D,
	0xC4,0x00,0xC4,0x3B,0xD2,0xCB,0x1E,0x3D,0x1A,0x27,0xB3,0x3B,0x8C,0x95,0x3E,0x3D,0xF6,0xB3,0x42,0x3B,0x08,0x1B,0xA1,0x3D,0x20,0xEF,0xB8,0x3D,0x1E,0x6A,0x84,0x3D,0x65,0x26,0xCB,0x3D,0xF3,0x6B,0x3F,0x3D,0x0B,0x34,0x57,0x3B,0x65,0x3A,0x4B,0x3C,0x3E,0xB2,0x24,0x3D,0x0C,0xD4,0x58,0x3C,0xB8,0xF0,0xB7,0x3D,0xFA,0x56,0x93,0x3C,0xF3,0xA3,0x3F,0x3D,0xD2,0x13,0x1F,0x3C,0x0D,0x84,0xD9,0x3C,0x8B,0xFA,0x70,0x3C,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0xE2,0xDD,0x04,0x3E,0x01,0x57,0x64,0x3D,0x00,0x00,0x80,0x3F,0xC2,0xE3,0x19,0x3F,0xBE,0x0B,0x83,0x3D,0x20,0x45,0x8A,0x3E,0x84,0x2C,0xA1,0x3E,0xA6,0x67,0xC0,0x3E,0x7A,0x31,0xF9,0x3D,0xA6,0x58,0x00,0x3F,0x00,0x00,0x00,0x00,0x41,0xBD,0x1D,0x3E,0xF6,0x55,0x21,0x3E,0xE9,0xE0,0xA0,0x3E,0x96,0xFD,0x97,0x3B,0x3D,0x96,0xB5,0x3B,0x85,0xB5,0x58,0x3D,0x02,0x77,0x8E,0x2D,0x24,0xA5,0x0E,0x3E,0x00,0x00,0x00,0x00,0xFE,0x07,0x04,0x3E,0x12,0xC2,0x97,0x2D,0xF5,0xFD,0x23,0x3E,0x00,0x00,0x00,0x00,0xB3,0xA4,0x38,0x3E,0x09,0x8D,0x25,0x3D,0x67,0xF8,0x32,0x3D,0x1C,0xD1,0xAE,0x3D,0x16,0x85,0x9C,0x3E,0x9C,0x54,0x9C,0x3D,0x57,0xE7,0x6F,0x3B,0x4C,0x36,0xB2,0x3D,0x21,0x76,0x87,0x3D,0xD0,0xF3,0x9C,0x3C,0x57,0x9A,0xBD,0x3D,0x27,0xBB,0xC0,0x3D,0x8C,0xD4,0x8B,0x3D,0xE8,0xEF,0xB4,0x3D,0x43,0xE6,0xA8,0x3D,0x1D,0xF3,0xB5,0x3D,0xB6,0x40,0xB6,0x3C,
	0xA7,0xA4,0xA6,0x3D,0x28,0x27,0xC1,0x3B,0x2D,0x64,0xF9,0x3C,0xE5,0xFF,0xB1,0x3D,0x5D,0x62,0xC3,0x3D,0x52,0x71,0x85,0x3D,0x7A,0x12,0x60,0x3D,0x72,0xB9,0xA4,0x3D,0xED,0xFE,0x85,0x3D,0xB6,0xF0,0x35,0x3D,0xBC,0xE3,0x88,0x3C,0x10,0x87,0xA9,0x3C,0x63,0xFA,0xC8,0x3C,0x4A,0x2F,0x63,0x3D,0x60,0xC6,0xC5,0x3D,0x92,0xD0,0x91,0x3D,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x00,0x00,0x80,0x3F,0x61,0x79,0x99,0x3D,0x06,0x57,0x38,0x3F,0xC9,0xBE,0x76,0x3F,0x3A,0x98,0x48,0x3F,0x39,0xDE,0x28,0x3E,0x22,0xFD,0xD9,0x3E,0x0A,0x9C,0xE1,0x3D,0x41,0xF0,0xA7,0x3E,0x42,0x10,0x31,0x3D,0xAC,0xF5,0x0B,0x3F,0x00,0x00,0x00,0x00,0x5A,0x87,0x18,0x3E,0x5D,0x2C,0xFF,0x3D,0xA3,0xA9,0x23,0x3F,0x00,0x00,0x00,0x00,0x1A,0x47,0x1A,0x3D,0xD9,0x37,0x91,0x3D,0x7B,0xE5,0xEE,0x31,0x37,0x55,0x41,0x3E,0x00,0x00,0x00,0x00,0xB3,0xD4,0xF6,0x3C,0xD5,0x2A,0xD4,0x31,0x90,0xF0,0xB9,0x3D,0x58,0xBD,0xFF,0x39,0x98,0x99,0x22,0x3E,0x5E,0x2D,0x11,0x3D,0x9A,0x88,0x19,0x3D,0x98,0x24,0x98,0x3D,0x89,0xBA,0x6E,0x3C,0xF0,0x73,0xBC,0x3D,0xBA,0x8B,0x86,0x3D,0x98,0x4D,0xCB,0x3C,0xAC,0xA4,0xAB,0x3D,0x0B,0x24,0xD7,0x3C,0xCD,0x4B,0x99,0x3D,0xF5,0x12,0x8E,0x3D,0xFB,0x06,0x94,0x3C,0x2D,0x67,0xC6,0x3C,0x75,0xBA,0xDA,0x3C,0xBD,0x54,0xBC,0x3D,0x22,0x7A,0x88,0x3D,0xDA,0xDB,0x26,0x3D,0xFA,0x7B,0x46,0x3D,0xF5,0x80,0x74,0x3B,0xBF,0x2B,0x8B,0x3D,
	0x3A,0x9A,0xA0,0x3D,0x4F,0x89,0x82,0x3D,0x76,0x79,0xA9,0x3D,0xE3,0x53,0xAF,0x3D,0xCB,0x63,0x97,0x3C,0xB4,0xC4,0xB3,0x3D,0xBD,0x35,0x70,0x3D,0xB2,0x95,0x64,0x3D,0x9C,0x4D,0xCF,0x3C,0x53,0x9A,0xB9,0x38,0x60,0xCD,0x12,0x3A,0xED,0xAE,0x06,0x3D,0xDA,0xFF,0x7F,0x3F,0x4E,0xFF,0x7F,0x3F,0x5A,0xFF,0x7F,0x3F,0x20,0x1A,0x4C,0x3D,0x03,0xCC,0x9E,0x3E,0x47,0x05,0x7F,0x3F,0x5D,0x4B,0x2C,0x3F,0x2A,0x4C,0xC9,0x3C,0xC5,0xDC,0xBB,0x3E,0xCA,0xB1,0x44,0x3F,0xF2,0x8A,0x16,0x3F,0x0A,0x0C,0x55,0x3D,0x45,0xD5,0xC6,0x3E,0xDD,0xAD,0x61,0x2D,0xD7,0xAA,0xC4,0x3D,0xAF,0x12,0xBC,0x36,0x0A,0x45,0xF1,0x3E,0xD7,0xDB,0xDE,0x2C,0xE6,0x98,0xAC,0x3D,0xDF,0xE7,0x75,0x3C,0x00,0x00,0x00,0x00,0x35,0xDE,0x1A,0x3E,0x00,0x00,0x00,0x00,0xE5,0xB1,0xC6,0x3B,0x00,0x00,0x00,0x00,0xEE,0x85,0x39,0x3E,0x00,0x00,0x00,0x00,0xDD,0x27,0xE2,0x3B,0x00,0x00,0x00,0x00,0xC4,0xD5,0x49,0x3E,0x74,0xAC,0x82,0x3D,0x95,0x5F,0x8B,0x3C,0x5D,0xCA,0xC2,0x3D,0xC4,0x13,0x91,0x3D,0x1E,0x3C,0x6A,0x3D,0x0A,0xC4,0x56,0x3D,0x6D,0x05,0xA0,0x3D,0xC7,0xD5,0x79,0x3D,0x5C,0xE7,0x74,0x3C,0xFF,0xF6,0x17,0x3D,0xF0,0x20,0x70,0x3D,0xA9,0x50,0xA9,0x3C,0x4E,0x69,0x81,0x3D,0x41,0x7A,0xA7,0x3C,0x57,0xE7,0xEF,0x3B,0x07,0x77,0xA0,0x3D,0xC4,0xE0,0x43,0x3C,0x4B,0x62,0x31,0x3D,0x00,0x90,0xCC,0x3D,0x5A,0x95,0x0C,0x3D,0x92,0x80,0x91,0x3B,0xB7,0xC3,0x03,0x3D,
	0xC4,0xFB,0x90,0x3D,0x86,0x61,0xB9,0x3D,0x2B,0xF3,0xC3,0x3D,0x59,0x7A,0x3F,0x3C,0x9A,0xAD,0xCC,0x3D,0x4D,0xFA,0xB2,0x3C,0x7D,0x99,0xAF,0x3D,0xFB,0xA6,0x94,0x3C,0xBC,0xFC,0x7F,0x3F,0xE5,0xF0,0x7F,0x3F,0xE0,0xF1,0x7F,0x3F,0x00,0x00,0x00,0x00,0x1E,0xDB,0xE4,0x3E,0x0B,0x09,0x03,0x3F,0xAC,0x4C,0xC6,0x3E,0x00,0x00,0x00,0x00,0x73,0x4B,0xB8,0x3E,0x00,0x00,0x80,0x3F,0x8A,0x5A,0x4A,0x3F,0x85,0x06,0x4F,0x37,0x6D,0x87,0x16,0x3F,0x00,0x00,0x00,0x00,0xDE,0x88,0x7A,0x3D,0x00,0x00,0x00,0x00,0xA0,0x8B,0x00,0x3F,0x6C,0x79,0x0F,0x3C,0x0E,0xC9,0x45,0x3E,0x00,0x00,0x00,0x00,0x4C,0xC6,0xE8,0x3C,0xD3,0x3D,0xE4,0x3D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDA,0x63,0x0C,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x91,0xA8,0x3C,0xF8,0x10,0x66,0x3D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xB3,0xA4,0x3D,0x44,0x3A,0xAA,0x3D,0x6D,0xBA,0x52,0x3D,0xA7,0x6C,0xA6,0x3D,0x97,0xAD,0xC9,0x3D,0xFE,0xC0,0x7D,0x3C,0x81,0x05,0x34,0x3D,0x32,0x87,0xCB,0x3D,0xE6,0xDB,0x32,0x3D,0x1B,0x7C,0x67,0x3D,0xB7,0x8B,0x83,0x3D,0x29,0x1C,0x75,0x3D,0x51,0x77,0xEA,0x3C,0x95,0x64,0x94,0x3D,0xA9,0x24,0xA9,0x3D,0x21,0xF2,0x06,0x3D,0x8C,0x8D,0x3E,0x3C,0x6D,0xDA,0xD2,0x3C,0xDB,0xE3,0x27,0x3D,0xC9,0xC8,0xC8,0x3D,0x9C,0x48,0x9C,0x3D,0xD2,0xA0,0xD1,0x3C,0x51,0x15,0x84,0x3D,0xE5,0x88,0x64,0x3D,
	0x37,0xC2,0x9C,0x3D,0x8E,0xDC,0x8D,0x3D,0x9A,0xCD,0x4C,0x37,0xDD,0xA3,0xA9,0x3C
},

/* input data and other run-time fields*/

{0}

}; /* done */
