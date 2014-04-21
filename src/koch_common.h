
/**
 * Fichier : koch_common.h
 * Description : Trace de fractales geometriques
                 Header commun
 * Auteur : Léo Gouttefarde
 * Date : 21/04/2014
 */

#ifndef _KOCH_COMMON_H_
#define _KOCH_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <complex.h>
#include <inttypes.h>

// defines
#define DEGREE_TO_RADIAN(x) ((x * 180) / PI)

// Log
#define LOG_LEVEL 3
#define TRACE(__level,__message) if ( __level >= LOG_LEVEL ) { puts(__message".\n"); }
#define INFO(__message) printf("[%s: %s, l.%d] %s.\n", __FILE__, __func__, __LINE__, __message);

// Other
#define UNUSED(arg) ((void)(arg))
#define SAFE_FREE(p) if (p) { free(p); p = NULL; }

// structs

// enums

#endif
