/* $Header: EXTERN.h,v 2.0 86/09/17 15:35:37 lwall Exp $
 *
 * $Log:	EXTERN.h,v $
 * Revision 2.0  86/09/17  15:35:37  lwall
 * Baseline for netwide release.
 * 
 */

#ifdef EXT
#undef EXT
#endif
#define EXT extern

#ifdef INIT
#undef INIT
#endif
#define INIT(x)

#ifdef DOINIT
#undef DOINIT
#endif

#ifndef PARAMS
#if __STDC__
#define PARAMS(args) args
#else
#define PARAMS(args) ()
#endif
#endif

#if __GNUC__ && !__STRICT_ANSI__
#define EXITING volatile
#else
#define EXITING
#endif
