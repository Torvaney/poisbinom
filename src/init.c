#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP _poisbinom_dpoisbinom(SEXP, SEXP, SEXP);
extern SEXP _poisbinom_ppoisbinom(SEXP, SEXP, SEXP, SEXP);
extern SEXP _poisbinom_qpoisbinom(SEXP, SEXP, SEXP, SEXP);
extern SEXP _poisbinom_rpoisbinom(SEXP, SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_poisbinom_dpoisbinom", (DL_FUNC) &_poisbinom_dpoisbinom, 3},
    {"_poisbinom_ppoisbinom", (DL_FUNC) &_poisbinom_ppoisbinom, 4},
    {"_poisbinom_qpoisbinom", (DL_FUNC) &_poisbinom_qpoisbinom, 4},
    {"_poisbinom_rpoisbinom", (DL_FUNC) &_poisbinom_rpoisbinom, 2},
    {NULL, NULL, 0}
};

void R_init_poisbinom(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
