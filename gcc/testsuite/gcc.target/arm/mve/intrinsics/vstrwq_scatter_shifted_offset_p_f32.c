/* { dg-require-effective-target arm_v8_1m_mve_fp_ok } */
/* { dg-add-options arm_v8_1m_mve_fp } */
/* { dg-additional-options "-O2" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "arm_mve.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
**foo:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vstrwt.32	q[0-9]+, \[(?:ip|fp|r[0-9]+), q[0-9]+, uxtw #2\](?:	@.*|)
**	...
*/
void
foo (float32_t *base, uint32x4_t offset, float32x4_t value, mve_pred16_t p)
{
  return vstrwq_scatter_shifted_offset_p_f32 (base, offset, value, p);
}


/*
**foo1:
**	...
**	vmsr	p0, (?:ip|fp|r[0-9]+)(?:	@.*|)
**	...
**	vpst(?:	@.*|)
**	...
**	vstrwt.32	q[0-9]+, \[(?:ip|fp|r[0-9]+), q[0-9]+, uxtw #2\](?:	@.*|)
**	...
*/
void
foo1 (float32_t *base, uint32x4_t offset, float32x4_t value, mve_pred16_t p)
{
  return vstrwq_scatter_shifted_offset_p (base, offset, value, p);
}

#ifdef __cplusplus
}
#endif

/* { dg-final { scan-assembler-not "__ARM_undef" } } */