/* This file is automatically generated by SCOptimizer */

#include "mcinfer.h"

fuzzy_model model={

0, /* model_ready set to OK */
3, /* engine code (algorithm type) */
1, /* min_inference_mode */
1, /* database type */
2, /* number of input variables */
4, /* number of output variables */

/* Input variable normalization parameters */
{{0.001053f,-0.057895f},{0.002155f,-0.088362f}},

/* Output variable normalization parameters */
{{0.010526f,-0.105263f},{0.014925f,0.000000f},{0.016949f,-1.881356f},{0.005556f,0.000000f}},

/* number of input MF's per variable*/ 
{20,20},
/* input MF paramteres */ 
{
	{triangular,0.016751f,0,0.019080f,0.019080f},{triangular,0.072408f,0,0.044318f,0.044318f},{triangular,0.151132f,0,0.045354f,0.045354f},{triangular,0.206717f,0,0.017962f,0.017962f},{triangular,0.247686f,0,0.028705f,0.028705f},{triangular,0.288752f,0,0.018073f,0.018073f},{triangular,0.314568f,0,0.011334f,0.011334f},{triangular,0.347432f,0,0.026100f,0.026100f},{triangular,0.385617f,0,0.017395f,0.017395f},{triangular,0.405840f,0,0.005641f,0.005641f},{triangular,0.431048f,0,0.023072f,0.023072f},{triangular,0.481379f,0,0.034260f,0.034260f},{triangular,0.551214f,0,0.045289f,0.045288f},{triangular,0.617448f,0,0.030157f,0.030157f},{triangular,0.680540f,0,0.041709f,0.041709f},{triangular,0.734185f,0,0.019397f,0.019397f},{triangular,0.781690f,0,0.034715f,0.034715f},{triangular,0.847464f,0,0.040206f,0.040206f},{triangular,0.922357f,0,0.045104f,0.045104f},{triangular,0.980977f,0,0.021669f,0.021669f},
	{desc_normal,0.017229f,0,0,0.030178f},{normal,0.047696f,0,0,0.023186f},{normal,0.095382f,0,0,0.060339f},{normal,0.134522f,0,0,0.008218f},{normal,0.153826f,0,0,0.025594f},{normal,0.200339f,0,0,0.055874f},{normal,0.253750f,0,0,0.037678f},{normal,0.318105f,0,0,0.075044f},{normal,0.364568f,0,0,0.006338f},{normal,0.393766f,0,0,0.044803f},{normal,0.427653f,0,0,0.014553f},{normal,0.450972f,0,0,0.026290f},{normal,0.480694f,0,0,0.025770f},{normal,0.534650f,0,0,0.068736f},{normal,0.593096f,0,0,0.033636f},{normal,0.650839f,0,0,0.067502f},{normal,0.711962f,0,0,0.039560f},{normal,0.778379f,0,0,0.076773f},{normal,0.864704f,0,0,0.074429f},{asc_normal,0.953599f,0,0.081275f,0}
	},

/* number of output MF's per variable*/ 
{5,4,3,10},
/* output MF paramteres */ 
{
	{descending,0.066917f,0,0,0.104878f},{triangular,0.213158f,0,0.114464f,0.138146f},{triangular,0.393985f,0,0.133071f,0.111644f},{triangular,0.633835f,0,0.248099f,0.296591f},{ascending,0.889474f,0,0.086835f,0},
	{descending,0.091211f,0,0,0.235810f},{triangular,0.370500f,0,0.135341f,0.301017f},{triangular,0.671642f,0,0.099172f,0.009917f},{ascending,0.804214f,0,0.166259f,0},
	{descending,0.099576f,0,0,0.129342f},{triangular,0.436610f,0,0.372504f,0.435092f},{ascending,0.825833f,0,0.144462f,0},
	{desc_normal,0.077778f,0,0,0.130182f},{normal,0.251389f,0,0,0.160402f},{normal,0.387500f,0,0,0.067415f},{normal,0.466667f,0,0,0.065091f},{normal,0.516667f,0,0,0.018597f},{normal,0.586111f,0,0,0.097636f},{normal,0.663889f,0,0,0.032545f},{normal,0.715278f,0,0,0.053467f},{normal,0.787500f,0,0,0.067415f},{asc_normal,0.913889f,0,0.144130f,0}
	},

/* Rule database */
400, /*number of rules */

/* index */
{0}, /* empty */
/* database */
{
	0x03,0x00,0x02,0x01,0x03,0x01,0x02,0x08,0x02,0x00,0x02,0x07,0x03,0x03,0x01,0x03,0x03,0x00,0x01,0x08,0x03,0x03,0x00,0x03,0x01,0x03,0x00,0x06,0x03,0x03,0x02,0x08,0x03,0x03,0x02,0x09,0x03,0x03,0x02,0x08,0x01,0x02,0x02,0x09,0x02,0x01,0x02,0x07,0x04,0x03,0x01,0x09,0x01,0x02,0x01,0x09,0x01,0x03,0x01,0x05,0x03,0x01,0x01,0x01,
	0x03,0x02,0x01,0x09,0x03,0x02,0x01,0x09,0x01,0x01,0x01,0x09,0x01,0x03,0x01,0x01,0x01,0x03,0x01,0x02,0x02,0x01,0x00,0x08,0x02,0x01,0x00,0x01,0x04,0x00,0x02,0x08,0x02,0x01,0x02,0x06,0x02,0x02,0x01,0x09,0x03,0x01,0x01,0x05,0x02,0x02,0x01,0x08,0x02,0x02,0x01,0x08,0x02,0x02,0x01,0x08,0x01,0x01,0x01,0x03,0x01,0x01,0x01,0x03,
	0x02,0x01,0x01,0x01,0x02,0x02,0x01,0x04,0x01,0x03,0x01,0x01,0x01,0x01,0x01,0x09,0x03,0x01,0x01,0x08,0x02,0x01,0x01,0x09,0x01,0x01,0x01,0x09,0x01,0x01,0x01,0x01,0x02,0x02,0x00,0x08,0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x03,0x02,0x05,0x03,0x02,0x01,0x09,0x02,0x01,0x01,0x08,0x01,0x01,0x01,0x09,0x02,0x01,0x01,0x08,
	0x02,0x03,0x02,0x08,0x02,0x01,0x01,0x09,0x02,0x03,0x02,0x07,0x01,0x02,0x01,0x08,0x01,0x03,0x01,0x08,0x01,0x02,0x02,0x09,0x04,0x02,0x02,0x08,0x01,0x02,0x02,0x01,0x02,0x02,0x01,0x05,0x03,0x02,0x01,0x04,0x04,0x02,0x02,0x00,0x02,0x02,0x02,0x06,0x01,0x02,0x02,0x01,0x04,0x01,0x02,0x03,0x03,0x02,0x01,0x07,0x03,0x02,0x01,0x02,
	0x03,0x02,0x01,0x08,0x03,0x02,0x01,0x08,0x04,0x01,0x01,0x01,0x02,0x01,0x01,0x08,0x02,0x01,0x01,0x08,0x04,0x02,0x01,0x01,0x01,0x01,0x01,0x05,0x02,0x03,0x01,0x09,0x03,0x00,0x02,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x05,
	0x01,0x02,0x02,0x09,0x01,0x02,0x02,0x03,0x03,0x03,0x02,0x07,0x03,0x03,0x01,0x06,0x02,0x02,0x02,0x07,0x01,0x01,0x01,0x06,0x03,0x01,0x02,0x04,0x01,0x01,0x01,0x06,0x03,0x01,0x01,0x07,0x00,0x00,0x00,0x07,0x01,0x01,0x01,0x07,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x03,
	0x02,0x03,0x02,0x05,0x00,0x00,0x00,0x04,0x03,0x03,0x02,0x01,0x00,0x01,0x01,0x04,0x02,0x01,0x01,0x06,0x02,0x02,0x01,0x02,0x03,0x02,0x01,0x06,0x03,0x02,0x01,0x04,0x03,0x02,0x01,0x05,0x02,0x01,0x01,0x04,0x01,0x01,0x01,0x05,0x01,0x01,0x01,0x01,0x00,0x00,0x02,0x06,0x00,0x00,0x00,0x07,0x01,0x00,0x00,0x07,0x00,0x00,0x00,0x07,
	0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x06,0x04,0x03,0x01,0x05,0x00,0x00,0x00,0x09,0x03,0x00,0x00,0x06,0x04,0x01,0x01,0x02,0x01,0x03,0x02,0x01,0x03,0x02,0x02,0x01,0x02,0x03,0x02,0x06,0x02,0x03,0x02,0x07,0x02,0x03,0x02,0x07,0x04,0x01,0x02,0x03,0x04,0x01,0x01,0x02,0x00,0x01,0x00,0x06,
	0x03,0x03,0x02,0x03,0x00,0x01,0x00,0x07,0x00,0x01,0x00,0x07,0x00,0x01,0x00,0x07,0x00,0x01,0x00,0x07,0x00,0x01,0x00,0x07,0x00,0x01,0x00,0x05,0x00,0x01,0x00,0x02,0x02,0x01,0x01,0x01,0x00,0x01,0x00,0x09,0x01,0x02,0x02,0x03,0x03,0x01,0x01,0x04,0x03,0x01,0x02,0x03,0x04,0x01,0x01,0x07,0x02,0x03,0x01,0x05,0x03,0x03,0x01,0x05,
	0x03,0x03,0x01,0x05,0x01,0x01,0x00,0x03,0x01,0x01,0x02,0x03,0x00,0x00,0x01,0x03,0x01,0x01,0x00,0x09,0x00,0x00,0x01,0x07,0x00,0x00,0x01,0x07,0x00,0x00,0x01,0x07,0x00,0x00,0x01,0x07,0x00,0x00,0x01,0x06,0x00,0x00,0x01,0x05,0x00,0x00,0x01,0x07,0x04,0x02,0x02,0x04,0x00,0x00,0x01,0x06,0x03,0x02,0x02,0x06,0x04,0x01,0x02,0x00,
	0x02,0x01,0x02,0x01,0x03,0x02,0x02,0x09,0x02,0x02,0x01,0x05,0x02,0x02,0x01,0x05,0x02,0x02,0x01,0x05,0x02,0x02,0x01,0x03,0x01,0x01,0x02,0x06,0x03,0x02,0x01,0x08,0x04,0x00,0x01,0x09,0x03,0x03,0x00,0x05,0x01,0x00,0x00,0x06,0x01,0x01,0x00,0x07,0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x07,
	0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x06,0x03,0x03,0x02,0x05,0x04,0x03,0x02,0x03,0x03,0x01,0x02,0x04,0x02,0x03,0x01,0x05,0x03,0x03,0x01,0x05,0x01,0x00,0x00,0x03,0x02,0x00,0x01,0x04,0x01,0x00,0x00,0x03,0x03,0x02,0x00,0x03,0x01,0x00,0x00,0x06,0x01,0x00,0x00,0x06,0x01,0x00,0x00,0x06,
	0x01,0x00,0x00,0x06,0x01,0x00,0x00,0x05,0x04,0x02,0x02,0x03,0x01,0x00,0x00,0x07,0x01,0x01,0x02,0x07,0x00,0x00,0x00,0x07,0x02,0x01,0x02,0x02,0x04,0x00,0x01,0x04,0x03,0x02,0x01,0x04,0x03,0x02,0x01,0x05,0x03,0x01,0x01,0x04,0x03,0x02,0x02,0x02,0x00,0x03,0x01,0x06,0x02,0x01,0x01,0x05,0x03,0x00,0x01,0x05,0x02,0x01,0x01,0x05,
	0x04,0x00,0x01,0x09,0x04,0x01,0x01,0x08,0x03,0x02,0x02,0x01,0x00,0x02,0x02,0x09,0x00,0x02,0x01,0x09,0x01,0x02,0x01,0x04,0x03,0x01,0x02,0x08,0x04,0x00,0x01,0x01,0x01,0x02,0x02,0x04,0x03,0x03,0x02,0x08,0x04,0x01,0x01,0x09,0x02,0x03,0x02,0x01,0x02,0x01,0x01,0x04,0x02,0x01,0x01,0x03,0x02,0x01,0x01,0x02,0x04,0x02,0x01,0x09,
	0x04,0x03,0x01,0x04,0x01,0x01,0x01,0x02,0x02,0x00,0x01,0x03,0x01,0x01,0x01,0x03,0x04,0x00,0x02,0x07,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x08,0x01,0x00,0x00,0x04,0x01,0x00,0x00,0x04,0x01,0x00,0x01,0x03,0x01,0x00,0x00,0x03,0x01,0x00,0x00,0x03,0x04,0x00,0x02,0x09,0x01,0x00,0x00,0x03,0x01,0x03,0x02,0x08,0x01,0x01,0x02,0x04,
	0x03,0x02,0x01,0x04,0x03,0x02,0x01,0x04,0x03,0x03,0x01,0x05,0x03,0x00,0x02,0x02,0x01,0x03,0x02,0x03,0x01,0x01,0x01,0x02,0x02,0x01,0x01,0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x02,0x03,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x07,0x00,0x01,0x01,0x04,0x00,0x01,0x01,0x02,0x00,0x01,0x01,0x02,0x00,0x01,0x01,0x02,0x00,0x01,0x01,0x02,
	0x00,0x00,0x00,0x05,0x00,0x01,0x01,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x07,0x04,0x02,0x01,0x02,0x04,0x02,0x01,0x04,0x01,0x02,0x01,0x01,0x04,0x03,0x00,0x07,0x02,0x03,0x01,0x08,0x01,0x03,0x01,0x01,0x01,0x03,0x01,0x02,0x01,0x02,0x01,0x01,0x01,0x00,0x01,0x02,0x01,0x01,0x01,0x01,0x00,0x02,0x02,0x06,0x01,0x02,0x02,0x02,
	0x00,0x01,0x00,0x03,0x01,0x01,0x01,0x02,0x00,0x01,0x00,0x01,0x00,0x00,0x01,0x01,0x01,0x02,0x02,0x06,0x04,0x01,0x02,0x01,0x03,0x01,0x01,0x01,0x02,0x02,0x01,0x02,0x01,0x02,0x01,0x01,0x03,0x02,0x01,0x01,0x01,0x02,0x01,0x01,0x01,0x02,0x01,0x01,0x01,0x03,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x02,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x01,0x00,0x01,0x09,0x03,0x00,0x01,0x06,0x00,0x00,0x00,0x09,0x00,0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x01,0x01,0x04,0x00,0x01,0x01,0x05,0x00,0x01,0x01,0x05,0x00,0x01,0x01,0x07,0x03,0x00,0x01,0x07,0x00,0x00,0x01,0x00,0x04,0x02,0x02,0x02,0x02,0x03,0x02,0x05,
	0x03,0x03,0x02,0x02,0x01,0x02,0x02,0x02,0x01,0x03,0x01,0x02,0x01,0x03,0x02,0x02,0x01,0x00,0x02,0x06,0x03,0x01,0x02,0x08,0x03,0x03,0x02,0x04,0x00,0x03,0x01,0x05,0x04,0x03,0x02,0x02,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x04,0x02,0x00,0x06,0x04,0x03,0x02,0x03,0x04,0x01,0x01,0x04,0x03,0x02,0x00,0x09,
	0x02,0x00,0x00,0x01,0x04,0x01,0x02,0x01,0x03,0x02,0x01,0x01,0x02,0x02,0x01,0x01,0x03,0x01,0x01,0x01,0x03,0x02,0x01,0x01,0x02,0x01,0x01,0x05,0x01,0x01,0x01,0x01,0x04,0x03,0x00,0x02,0x02,0x02,0x02,0x05,0x01,0x01,0x02,0x02,0x02,0x03,0x02,0x08,0x04,0x01,0x02,0x00,0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x03,0x02,0x05,0x04,0x02,0x00,0x01,0x01,0x01,0x01,0x05,0x03,0x01,0x02,0x05,0x03,0x02,0x01,0x02,0x03,0x02,0x01,0x02,0x03,0x02,0x01,0x01,0x03,0x02,0x01,0x01,0x03,0x03,0x01,0x01,0x03,0x01,0x01,0x01,0x03,0x02,0x02,0x01,0x04,0x03,0x02,0x01,
	0x04,0x01,0x02,0x04,0x01,0x02,0x01,0x01,0x01,0x03,0x00,0x05,0x01,0x01,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x01,0x00,0x01,0x00,0x00,0x04,0x03,0x02,0x06,0x04,0x03,0x01,0x03,0x04,0x01,0x01,0x08,0x01,0x03,0x00,0x01,0x01,0x00,0x01,0x03,0x03,0x02,0x02,0x06,0x03,0x01,0x01,0x00,0x03,0x02,0x01,0x00,0x03,0x02,0x01,0x01,
	0x00,0x03,0x00,0x06,0x03,0x02,0x01,0x01,0x03,0x01,0x01,0x00,0x03,0x01,0x01,0x01,0x03,0x01,0x01,0x01,0x03,0x01,0x01,0x01,0x04,0x03,0x01,0x01,0x03,0x01,0x01,0x01,0x01,0x01,0x02,0x01,0x03,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x03,0x02,0x02,0x08,0x01,0x03,0x01,0x07,0x02,0x03,0x02,0x05,0x04,0x03,0x01,0x05,
	0x02,0x01,0x01,0x09,0x00,0x01,0x01,0x07,0x03,0x03,0x02,0x08,0x01,0x02,0x01,0x00,0x02,0x01,0x01,0x03,0x03,0x00,0x02,0x05,0x03,0x02,0x02,0x00,0x02,0x03,0x01,0x03,0x04,0x02,0x02,0x05,0x03,0x02,0x01,0x00,0x03,0x02,0x01,0x00,0x03,0x01,0x01,0x00,0x03,0x01,0x01,0x00,0x03,0x02,0x01,0x00,0x03,0x02,0x01,0x00,0x03,0x02,0x01,0x00
},

/* input data and other run-time fields*/

{0}

}; /* done */
