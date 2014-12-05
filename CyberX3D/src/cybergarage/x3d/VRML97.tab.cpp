/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
/* Put the tokens into the symbol table, so that GDB and other debuggers
   know about them.  */
enum yytokentype
{
	NUMBER = 258,
	FLOAT = 259,
	STRING = 260,
	NAME = 261,
	ANCHOR = 262,
	APPEARANCE = 263,
	AUDIOCLIP = 264,
	BACKGROUND = 265,
	BILLBOARD = 266,
	BOX = 267,
	COLLISION = 268,
	COLOR = 269,
	COLOR_INTERP = 270,
	COORDINATE = 271,
	COORDINATE_INTERP = 272,
	CYLINDER_SENSOR = 273,
	NULL_STRING = 274,
	CONE = 275,
	CUBE = 276,
	CYLINDER = 277,
	DIRECTIONALLIGHT = 278,
	FONTSTYLE = 279,
	ERROR = 280,
	EXTRUSION = 281,
	ELEVATION_GRID = 282,
	FOG = 283,
	INLINE = 284,
	MOVIE_TEXTURE = 285,
	NAVIGATION_INFO = 286,
	PIXEL_TEXTURE = 287,
	GROUP = 288,
	INDEXEDFACESET = 289,
	INDEXEDLINESET = 290,
	S_INFO = 291,
	LOD = 292,
	MATERIAL = 293,
	NORMAL = 294,
	POSITION_INTERP = 295,
	PROXIMITY_SENSOR = 296,
	SCALAR_INTERP = 297,
	SCRIPT = 298,
	SHAPE = 299,
	SOUND = 300,
	SPOTLIGHT = 301,
	SPHERE_SENSOR = 302,
	TEXT = 303,
	TEXTURE_COORDINATE = 304,
	TEXTURE_TRANSFORM = 305,
	TIME_SENSOR = 306,
	SWITCH = 307,
	TOUCH_SENSOR = 308,
	VIEWPOINT = 309,
	VISIBILITY_SENSOR = 310,
	WORLD_INFO = 311,
	NORMAL_INTERP = 312,
	ORIENTATION_INTERP = 313,
	POINTLIGHT = 314,
	POINTSET = 315,
	SPHERE = 316,
	PLANE_SENSOR = 317,
	TRANSFORM = 318,
	S_CHILDREN = 319,
	S_PARAMETER = 320,
	S_URL = 321,
	S_MATERIAL = 322,
	S_TEXTURETRANSFORM = 323,
	S_TEXTURE = 324,
	S_LOOP = 325,
	S_STARTTIME = 326,
	S_STOPTIME = 327,
	S_GROUNDANGLE = 328,
	S_GROUNDCOLOR = 329,
	S_SPEED = 330,
	S_AVATAR_SIZE = 331,
	S_BACKURL = 332,
	S_BOTTOMURL = 333,
	S_FRONTURL = 334,
	S_LEFTURL = 335,
	S_RIGHTURL = 336,
	S_TOPURL = 337,
	S_SKYANGLE = 338,
	S_SKYCOLOR = 339,
	S_AXIS_OF_ROTATION = 340,
	S_COLLIDE = 341,
	S_COLLIDETIME = 342,
	S_PROXY = 343,
	S_SIDE = 344,
	S_AUTO_OFFSET = 345,
	S_DISK_ANGLE = 346,
	S_ENABLED = 347,
	S_MAX_ANGLE = 348,
	S_MIN_ANGLE = 349,
	S_OFFSET = 350,
	S_BBOXSIZE = 351,
	S_BBOXCENTER = 352,
	S_VISIBILITY_LIMIT = 353,
	S_AMBIENT_INTENSITY = 354,
	S_NORMAL = 355,
	S_TEXCOORD = 356,
	S_CCW = 357,
	S_COLOR_PER_VERTEX = 358,
	S_CREASE_ANGLE = 359,
	S_NORMAL_PER_VERTEX = 360,
	S_XDIMENSION = 361,
	S_XSPACING = 362,
	S_ZDIMENSION = 363,
	S_ZSPACING = 364,
	S_BEGIN_CAP = 365,
	S_CROSS_SECTION = 366,
	S_END_CAP = 367,
	S_SPINE = 368,
	S_FOG_TYPE = 369,
	S_VISIBILITY_RANGE = 370,
	S_HORIZONTAL = 371,
	S_JUSTIFY = 372,
	S_LANGUAGE = 373,
	S_LEFT2RIGHT = 374,
	S_TOP2BOTTOM = 375,
	IMAGE_TEXTURE = 376,
	S_SOLID = 377,
	S_KEY = 378,
	S_KEYVALUE = 379,
	S_REPEAT_S = 380,
	S_REPEAT_T = 381,
	S_CONVEX = 382,
	S_BOTTOM = 383,
	S_PICTH = 384,
	S_COORD = 385,
	S_COLOR_INDEX = 386,
	S_COORD_INDEX = 387,
	S_NORMAL_INDEX = 388,
	S_MAX_POSITION = 389,
	S_MIN_POSITION = 390,
	S_ATTENUATION = 391,
	S_APPEARANCE = 392,
	S_GEOMETRY = 393,
	S_DIRECT_OUTPUT = 394,
	S_MUST_EVALUATE = 395,
	S_MAX_BACK = 396,
	S_MIN_BACK = 397,
	S_MAX_FRONT = 398,
	S_MIN_FRONT = 399,
	S_PRIORITY = 400,
	S_SOURCE = 401,
	S_SPATIALIZE = 402,
	S_BERM_WIDTH = 403,
	S_CHOICE = 404,
	S_WHICHCHOICE = 405,
	S_FONTSTYLE = 406,
	S_LENGTH = 407,
	S_MAX_EXTENT = 408,
	S_ROTATION = 409,
	S_SCALE = 410,
	S_CYCLE_INTERVAL = 411,
	S_FIELD_OF_VIEW = 412,
	S_JUMP = 413,
	S_TITLE = 414,
	S_TEXCOORD_INDEX = 415,
	S_HEADLIGHT = 416,
	S_TOP = 417,
	S_BOTTOMRADIUS = 418,
	S_HEIGHT = 419,
	S_POINT = 420,
	S_STRING = 421,
	S_SPACING = 422,
	S_TYPE = 423,
	S_RADIUS = 424,
	S_ON = 425,
	S_INTENSITY = 426,
	S_COLOR = 427,
	S_DIRECTION = 428,
	S_SIZE = 429,
	S_FAMILY = 430,
	S_STYLE = 431,
	S_RANGE = 432,
	S_CENTER = 433,
	S_TRANSLATION = 434,
	S_LEVEL = 435,
	S_DIFFUSECOLOR = 436,
	S_SPECULARCOLOR = 437,
	S_EMISSIVECOLOR = 438,
	S_SHININESS = 439,
	S_TRANSPARENCY = 440,
	S_VECTOR = 441,
	S_POSITION = 442,
	S_ORIENTATION = 443,
	S_LOCATION = 444,
	S_CUTOFFANGLE = 445,
	S_WHICHCHILD = 446,
	S_IMAGE = 447,
	S_SCALEORIENTATION = 448,
	S_DESCRIPTION = 449,
	SFBOOL = 450,
	SFFLOAT = 451,
	SFINT32 = 452,
	SFTIME = 453,
	SFROTATION = 454,
	SFNODE = 455,
	SFCOLOR = 456,
	SFIMAGE = 457,
	SFSTRING = 458,
	SFVEC2F = 459,
	SFVEC3F = 460,
	MFBOOL = 461,
	MFFLOAT = 462,
	MFINT32 = 463,
	MFTIME = 464,
	MFROTATION = 465,
	MFNODE = 466,
	MFCOLOR = 467,
	MFIMAGE = 468,
	MFSTRING = 469,
	MFVEC2F = 470,
	MFVEC3F = 471,
	FIELD = 472,
	EVENTIN = 473,
	EVENTOUT = 474,
	USE = 475,
	S_VALUE_CHANGED = 476
};
#endif
#define NUMBER 258
#define FLOAT 259
#define STRING 260
#define NAME 261
#define ANCHOR 262
#define APPEARANCE 263
#define AUDIOCLIP 264
#define BACKGROUND 265
#define BILLBOARD 266
#define BOX 267
#define COLLISION 268
#define COLOR 269
#define COLOR_INTERP 270
#define COORDINATE 271
#define COORDINATE_INTERP 272
#define CYLINDER_SENSOR 273
#define NULL_STRING 274
#define CONE 275
#define CUBE 276
#define CYLINDER 277
#define DIRECTIONALLIGHT 278
#define FONTSTYLE 279
#define ERROR 280
#define EXTRUSION 281
#define ELEVATION_GRID 282
#define FOG 283
#define INLINE 284
#define MOVIE_TEXTURE 285
#define NAVIGATION_INFO 286
#define PIXEL_TEXTURE 287
#define GROUP 288
#define INDEXEDFACESET 289
#define INDEXEDLINESET 290
#define S_INFO 291
#define LOD 292
#define MATERIAL 293
#define NORMAL 294
#define POSITION_INTERP 295
#define PROXIMITY_SENSOR 296
#define SCALAR_INTERP 297
#define SCRIPT 298
#define SHAPE 299
#define SOUND 300
#define SPOTLIGHT 301
#define SPHERE_SENSOR 302
#define TEXT 303
#define TEXTURE_COORDINATE 304
#define TEXTURE_TRANSFORM 305
#define TIME_SENSOR 306
#define SWITCH 307
#define TOUCH_SENSOR 308
#define VIEWPOINT 309
#define VISIBILITY_SENSOR 310
#define WORLD_INFO 311
#define NORMAL_INTERP 312
#define ORIENTATION_INTERP 313
#define POINTLIGHT 314
#define POINTSET 315
#define SPHERE 316
#define PLANE_SENSOR 317
#define TRANSFORM 318
#define S_CHILDREN 319
#define S_PARAMETER 320
#define S_URL 321
#define S_MATERIAL 322
#define S_TEXTURETRANSFORM 323
#define S_TEXTURE 324
#define S_LOOP 325
#define S_STARTTIME 326
#define S_STOPTIME 327
#define S_GROUNDANGLE 328
#define S_GROUNDCOLOR 329
#define S_SPEED 330
#define S_AVATAR_SIZE 331
#define S_BACKURL 332
#define S_BOTTOMURL 333
#define S_FRONTURL 334
#define S_LEFTURL 335
#define S_RIGHTURL 336
#define S_TOPURL 337
#define S_SKYANGLE 338
#define S_SKYCOLOR 339
#define S_AXIS_OF_ROTATION 340
#define S_COLLIDE 341
#define S_COLLIDETIME 342
#define S_PROXY 343
#define S_SIDE 344
#define S_AUTO_OFFSET 345
#define S_DISK_ANGLE 346
#define S_ENABLED 347
#define S_MAX_ANGLE 348
#define S_MIN_ANGLE 349
#define S_OFFSET 350
#define S_BBOXSIZE 351
#define S_BBOXCENTER 352
#define S_VISIBILITY_LIMIT 353
#define S_AMBIENT_INTENSITY 354
#define S_NORMAL 355
#define S_TEXCOORD 356
#define S_CCW 357
#define S_COLOR_PER_VERTEX 358
#define S_CREASE_ANGLE 359
#define S_NORMAL_PER_VERTEX 360
#define S_XDIMENSION 361
#define S_XSPACING 362
#define S_ZDIMENSION 363
#define S_ZSPACING 364
#define S_BEGIN_CAP 365
#define S_CROSS_SECTION 366
#define S_END_CAP 367
#define S_SPINE 368
#define S_FOG_TYPE 369
#define S_VISIBILITY_RANGE 370
#define S_HORIZONTAL 371
#define S_JUSTIFY 372
#define S_LANGUAGE 373
#define S_LEFT2RIGHT 374
#define S_TOP2BOTTOM 375
#define IMAGE_TEXTURE 376
#define S_SOLID 377
#define S_KEY 378
#define S_KEYVALUE 379
#define S_REPEAT_S 380
#define S_REPEAT_T 381
#define S_CONVEX 382
#define S_BOTTOM 383
#define S_PICTH 384
#define S_COORD 385
#define S_COLOR_INDEX 386
#define S_COORD_INDEX 387
#define S_NORMAL_INDEX 388
#define S_MAX_POSITION 389
#define S_MIN_POSITION 390
#define S_ATTENUATION 391
#define S_APPEARANCE 392
#define S_GEOMETRY 393
#define S_DIRECT_OUTPUT 394
#define S_MUST_EVALUATE 395
#define S_MAX_BACK 396
#define S_MIN_BACK 397
#define S_MAX_FRONT 398
#define S_MIN_FRONT 399
#define S_PRIORITY 400
#define S_SOURCE 401
#define S_SPATIALIZE 402
#define S_BERM_WIDTH 403
#define S_CHOICE 404
#define S_WHICHCHOICE 405
#define S_FONTSTYLE 406
#define S_LENGTH 407
#define S_MAX_EXTENT 408
#define S_ROTATION 409
#define S_SCALE 410
#define S_CYCLE_INTERVAL 411
#define S_FIELD_OF_VIEW 412
#define S_JUMP 413
#define S_TITLE 414
#define S_TEXCOORD_INDEX 415
#define S_HEADLIGHT 416
#define S_TOP 417
#define S_BOTTOMRADIUS 418
#define S_HEIGHT 419
#define S_POINT 420
#define S_STRING 421
#define S_SPACING 422
#define S_TYPE 423
#define S_RADIUS 424
#define S_ON 425
#define S_INTENSITY 426
#define S_COLOR 427
#define S_DIRECTION 428
#define S_SIZE 429
#define S_FAMILY 430
#define S_STYLE 431
#define S_RANGE 432
#define S_CENTER 433
#define S_TRANSLATION 434
#define S_LEVEL 435
#define S_DIFFUSECOLOR 436
#define S_SPECULARCOLOR 437
#define S_EMISSIVECOLOR 438
#define S_SHININESS 439
#define S_TRANSPARENCY 440
#define S_VECTOR 441
#define S_POSITION 442
#define S_ORIENTATION 443
#define S_LOCATION 444
#define S_CUTOFFANGLE 445
#define S_WHICHCHILD 446
#define S_IMAGE 447
#define S_SCALEORIENTATION 448
#define S_DESCRIPTION 449
#define SFBOOL 450
#define SFFLOAT 451
#define SFINT32 452
#define SFTIME 453
#define SFROTATION 454
#define SFNODE 455
#define SFCOLOR 456
#define SFIMAGE 457
#define SFSTRING 458
#define SFVEC2F 459
#define SFVEC3F 460
#define MFBOOL 461
#define MFFLOAT 462
#define MFINT32 463
#define MFTIME 464
#define MFROTATION 465
#define MFNODE 466
#define MFCOLOR 467
#define MFIMAGE 468
#define MFSTRING 469
#define MFVEC2F 470
#define MFVEC3F 471
#define FIELD 472
#define EVENTIN 473
#define EVENTOUT 474
#define USE 475
#define S_VALUE_CHANGED 476




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
//#line 20 "VRML97.y"
typedef union YYSTYPE
{
	int		ival;
	float	fval;
	char	*sval;
} YYSTYPE;

/* Line 191 of yacc.c.  */
//#line 525 "VRML97.tab.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
//#line 72 "VRML97.y"


#include <stdio.h>
#include <stdlib.h>

#ifndef __GNUC__
#define alloca	malloc
#endif

#include <cybergarage/x3d/SceneGraph.h>
#include <cybergarage/x3d/NodeType.h>
#include <cybergarage/x3d/VRML97Parser.h>
#include <cybergarage/x3d/VRML97ParserFunc.h>

using namespace CyberX3D;

static float gColor[3];
static float gVec2f[2];
static float gVec3f[3];
static float gRotation[4];
static int gWidth;
static int gHeight;
static int gComponents;

#define YYINITDEPTH  (1024 * 64)
#define	YYMAXDEPTH	(YYINITDEPTH * 64)

int yyerror(char *s);
int yyparse(void);
int yylex(void);



/* Line 214 of yacc.c.  */
//#line 569 "VRML97.tab.cpp"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC malloc
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC malloc
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
/* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
	short yyss;
	YYSTYPE yyvs;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
typedef signed char yysigned_char;
#else
typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  146
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1859

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  227
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  295
/* YYNRULES -- Number of rules. */
#define YYNRULES  714
/* YYNRULES -- Number of states. */
#define YYNSTATES  1195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   476

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
	0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,   224,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,   222,     2,   223,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,   225,     2,   226,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
	5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
	15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
	25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
	35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
	55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
	65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
	75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
	85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
	95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
	105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
	115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
	125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
	135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
	145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
	155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
	165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
	175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
	185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
	195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
	205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
	215,   216,   217,   218,   219,   220,   221
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
	0,     0,     3,     5,     7,     9,    12,    13,    15,    17,
	19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
	39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
	59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
	79,    81,    83,    85,    87,    89,    91,    93,    95,    97,
	99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
	119,   121,   123,   125,   127,   129,   131,   133,   135,   137,
	139,   141,   143,   147,   152,   155,   156,   159,   163,   165,
	168,   171,   172,   174,   178,   180,   183,   186,   187,   189,
	193,   195,   198,   201,   202,   204,   208,   210,   213,   216,
	217,   219,   223,   225,   228,   231,   232,   234,   238,   240,
	243,   246,   247,   249,   253,   255,   258,   261,   262,   264,
	268,   270,   272,   275,   278,   279,   281,   283,   286,   289,
	291,   294,   297,   300,   302,   304,   306,   311,   314,   315,
	318,   321,   324,   327,   330,   333,   336,   339,   342,   345,
	348,   350,   355,   358,   359,   361,   364,   367,   370,   373,
	376,   379,   381,   386,   389,   390,   392,   394,   396,   398,
	400,   402,   404,   406,   408,   410,   413,   416,   419,   422,
	425,   428,   431,   434,   437,   440,   442,   447,   450,   451,
	453,   456,   458,   460,   462,   467,   470,   471,   474,   476,
	481,   484,   485,   490,   493,   496,   497,   499,   501,   504,
	506,   508,   511,   514,   517,   519,   524,   527,   528,   531,
	533,   538,   541,   542,   544,   546,   549,   552,   554,   559,
	562,   563,   566,   569,   572,   575,   577,   582,   585,   586,
	588,   593,   596,   597,   600,   603,   605,   610,   613,   614,
	617,   620,   623,   626,   629,   631,   636,   639,   640,   643,
	646,   649,   652,   655,   658,   660,   665,   668,   669,   672,
	675,   678,   681,   684,   686,   691,   694,   695,   697,   700,
	703,   706,   709,   712,   715,   718,   721,   724,   727,   730,
	733,   736,   739,   742,   745,   748,   751,   754,   756,   761,
	764,   765,   767,   769,   771,   773,   776,   779,   782,   785,
	788,   791,   794,   797,   800,   803,   805,   810,   813,   814,
	817,   820,   823,   825,   830,   833,   834,   836,   839,   842,
	845,   848,   851,   854,   857,   860,   863,   866,   870,   873,
	874,   876,   878,   880,   882,   887,   890,   891,   893,   896,
	899,   902,   904,   909,   912,   913,   915,   917,   919,   921,
	924,   927,   930,   933,   936,   939,   942,   945,   948,   951,
	954,   957,   960,   963,   966,   969,   972,   975,   978,   981,
	984,   987,   989,   994,   997,   998,  1001,  1004,  1007,  1010,
	1013,  1016,  1019,  1022,  1025,  1028,  1032,  1035,  1036,  1038,
	1041,  1043,  1045,  1047,  1052,  1055,  1056,  1058,  1060,  1063,
	1066,  1069,  1074,  1076,  1081,  1084,  1085,  1088,  1091,  1094,
	1097,  1100,  1103,  1105,  1110,  1113,  1114,  1116,  1119,  1122,
	1125,  1128,  1131,  1134,  1137,  1139,  1144,  1147,  1148,  1150,
	1152,  1155,  1158,  1161,  1164,  1167,  1169,  1174,  1177,  1178,
	1181,  1183,  1188,  1191,  1192,  1195,  1198,  1201,  1203,  1208,
	1211,  1212,  1215,  1218,  1221,  1223,  1228,  1231,  1232,  1234,
	1239,  1242,  1245,  1247,  1252,  1255,  1256,  1259,  1262,  1265,
	1268,  1271,  1273,  1278,  1281,  1282,  1285,  1288,  1291,  1294,
	1297,  1300,  1303,  1305,  1310,  1313,  1314,  1317,  1320,  1323,
	1326,  1329,  1332,  1334,  1339,  1342,  1343,  1346,  1349,  1352,
	1354,  1359,  1362,  1363,  1366,  1369,  1372,  1374,  1379,  1382,
	1383,  1386,  1389,  1392,  1394,  1399,  1402,  1403,  1405,  1408,
	1411,  1414,  1418,  1422,  1426,  1430,  1434,  1438,  1442,  1446,
	1450,  1454,  1458,  1462,  1466,  1470,  1474,  1478,  1482,  1486,
	1490,  1494,  1498,  1502,  1506,  1510,  1514,  1518,  1522,  1526,
	1530,  1534,  1538,  1542,  1546,  1550,  1554,  1558,  1563,  1568,
	1573,  1578,  1583,  1588,  1594,  1599,  1604,  1609,  1614,  1616,
	1621,  1624,  1625,  1628,  1631,  1634,  1637,  1640,  1643,  1645,
	1650,  1653,  1654,  1657,  1660,  1663,  1666,  1669,  1672,  1675,
	1678,  1681,  1684,  1687,  1690,  1693,  1695,  1700,  1703,  1704,
	1707,  1709,  1714,  1717,  1718,  1721,  1724,  1727,  1729,  1734,
	1737,  1738,  1741,  1744,  1747,  1750,  1753,  1756,  1759,  1762,
	1765,  1768,  1770,  1775,  1778,  1779,  1781,  1784,  1789,  1792,
	1794,  1799,  1802,  1803,  1805,  1807,  1810,  1813,  1816,  1819,
	1822,  1825,  1827,  1832,  1835,  1836,  1839,  1841,  1846,  1849,
	1850,  1853,  1856,  1859,  1862,  1864,  1869,  1872,  1873,  1876,
	1879,  1882,  1885,  1888,  1890,  1895,  1898,  1899,  1902,  1904,
	1909,  1912,  1913,  1915,  1918,  1921,  1924,  1927,  1930,  1932,
	1934,  1936,  1941,  1944,  1945,  1948,  1951,  1954,  1957,  1960,
	1962,  1967,  1970,  1971,  1974,  1977,  1980,  1982,  1987,  1990,
	1991,  1993,  1996,  1999,  2001
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
	228,     0,    -1,   229,    -1,     1,    -1,    25,    -1,   238,
	229,    -1,    -1,   272,    -1,   299,    -1,   310,    -1,   369,
	-1,   391,    -1,   397,    -1,   483,    -1,   509,    -1,   320,
	-1,   331,    -1,   420,    -1,   424,    -1,   445,    -1,   453,
	-1,   339,    -1,   433,    -1,   474,    -1,   449,    -1,   501,
	-1,   505,    -1,   515,    -1,   303,    -1,   324,    -1,   335,
	-1,   348,    -1,   356,    -1,   382,    -1,   386,    -1,   441,
	-1,   470,    -1,   489,    -1,   314,    -1,   327,    -1,   416,
	-1,   493,    -1,   276,    -1,   401,    -1,   343,    -1,   478,
	-1,   437,    -1,   281,    -1,   235,    -1,   458,    -1,   462,
	-1,   466,    -1,   521,    -1,   295,    -1,   360,    -1,   412,
	-1,   513,    -1,   236,    -1,   237,    -1,   365,    -1,   231,
	-1,   232,    -1,   230,    -1,   234,    -1,   220,    -1,     3,
	-1,     3,    -1,     5,    -1,     4,    -1,     3,    -1,     4,
	-1,     3,    -1,   242,   242,   242,    -1,   242,   242,   242,
	242,    -1,   239,   246,    -1,    -1,   242,   242,    -1,   242,
	242,   242,    -1,   244,    -1,   244,   249,    -1,   224,   249,
	-1,    -1,   244,    -1,   222,   249,   223,    -1,   239,    -1,
	239,   251,    -1,   224,   251,    -1,    -1,   239,    -1,   222,
	251,   223,    -1,   242,    -1,   242,   253,    -1,   224,   253,
	-1,    -1,   242,    -1,   222,   253,   223,    -1,   241,    -1,
	241,   255,    -1,   224,   255,    -1,    -1,   241,    -1,   222,
	255,   223,    -1,   247,    -1,   247,   257,    -1,   224,   257,
	-1,    -1,   247,    -1,   222,   257,   223,    -1,   248,    -1,
	248,   259,    -1,   224,   259,    -1,    -1,   248,    -1,   222,
	259,   223,    -1,   245,    -1,   245,   261,    -1,   224,   261,
	-1,    -1,   245,    -1,   222,   261,   223,    -1,   225,    -1,
	226,    -1,   226,   224,    -1,   270,   265,    -1,    -1,    65,
	-1,    66,    -1,    97,   248,    -1,    96,   248,    -1,   305,
	-1,   194,   241,    -1,   266,   256,    -1,   267,   256,    -1,
	268,    -1,   269,    -1,     7,    -1,   271,   263,   265,   264,
	-1,   274,   273,    -1,    -1,    67,    19,    -1,    67,   401,
	-1,    67,   220,    -1,    69,    19,    -1,    69,   374,    -1,
	69,   406,    -1,    69,   429,    -1,    69,   220,    -1,    68,
	19,    -1,    68,   497,    -1,    68,   220,    -1,     8,    -1,
	275,   263,   273,   264,    -1,   279,   277,    -1,    -1,    66,
	-1,   194,   241,    -1,    70,   240,    -1,   129,   242,    -1,
	71,   243,    -1,    72,   243,    -1,   278,   256,    -1,     9,
	-1,   280,   263,   277,   264,    -1,   293,   282,    -1,    -1,
	77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
	82,    -1,    73,    -1,    74,    -1,    83,    -1,    84,    -1,
	289,   254,    -1,   290,   250,    -1,   283,   256,    -1,   284,
	256,    -1,   285,   256,    -1,   286,   256,    -1,   287,   256,
	-1,   288,   256,    -1,   291,   254,    -1,   292,   250,    -1,
	10,    -1,   294,   263,   282,   264,    -1,   297,   296,    -1,
	-1,   305,    -1,    85,   248,    -1,   268,    -1,   269,    -1,
	11,    -1,   298,   263,   296,   264,    -1,   301,   300,    -1,
	-1,   174,   248,    -1,    12,    -1,   302,   263,   300,   264,
	-1,   238,   304,    -1,    -1,    64,   222,   304,   223,    -1,
	64,   238,    -1,   308,   306,    -1,    -1,    88,    -1,   305,
	-1,    86,   240,    -1,   268,    -1,   269,    -1,    88,   220,
	-1,    88,    19,    -1,   307,   238,    -1,    13,    -1,   309,
	263,   306,   264,    -1,   312,   311,    -1,    -1,   172,   250,
	-1,    14,    -1,   313,   263,   311,   264,    -1,   318,   315,
	-1,    -1,   123,    -1,   124,    -1,   316,   254,    -1,   317,
	250,    -1,    15,    -1,   319,   263,   315,   264,    -1,   322,
	321,    -1,    -1,    89,   240,    -1,   128,   240,    -1,   163,
	242,    -1,   164,   242,    -1,    20,    -1,   323,   263,   321,
	264,    -1,   165,   260,    -1,    -1,    16,    -1,   326,   263,
	325,   264,    -1,   329,   328,    -1,    -1,   316,   254,    -1,
	317,   260,    -1,    17,    -1,   330,   263,   328,   264,    -1,
	333,   332,    -1,    -1,    89,   240,    -1,   128,   240,    -1,
	162,   240,    -1,   169,   242,    -1,   164,   242,    -1,    22,
	-1,   334,   263,   332,   264,    -1,   337,   336,    -1,    -1,
	90,   240,    -1,    91,   242,    -1,    92,   240,    -1,    93,
	242,    -1,    94,   242,    -1,    95,   242,    -1,    18,    -1,
	338,   263,   336,   264,    -1,   341,   340,    -1,    -1,   170,
	240,    -1,   171,   242,    -1,   172,   244,    -1,   173,   248,
	-1,    99,   242,    -1,    23,    -1,   342,   263,   340,   264,
	-1,   346,   344,    -1,    -1,   164,    -1,   172,    19,    -1,
	172,   314,    -1,   172,   220,    -1,   100,    19,    -1,   100,
	416,    -1,   100,   220,    -1,   101,    19,    -1,   101,   493,
	-1,   101,   220,    -1,   345,   254,    -1,   102,   240,    -1,
	104,   242,    -1,   122,   240,    -1,   103,   240,    -1,   105,
	240,    -1,   106,   239,    -1,   107,   242,    -1,   108,   239,
	-1,   109,   242,    -1,    27,    -1,   347,   263,   344,   264,
	-1,   354,   349,    -1,    -1,   111,    -1,   188,    -1,   155,
	-1,   113,    -1,   110,   240,    -1,   102,   240,    -1,   127,
	240,    -1,   104,   242,    -1,   122,   240,    -1,   350,   258,
	-1,   112,   240,    -1,   351,   262,    -1,   352,   258,    -1,
	353,   260,    -1,    26,    -1,   355,   263,   349,   264,    -1,
	358,   357,    -1,    -1,   172,   244,    -1,   114,   241,    -1,
	115,   242,    -1,    28,    -1,   359,   263,   357,   264,    -1,
	363,   361,    -1,    -1,   117,    -1,   175,   241,    -1,   116,
	240,    -1,   362,   256,    -1,   118,   241,    -1,   119,   240,
	-1,   174,   242,    -1,   167,   242,    -1,   176,   241,    -1,
	120,   240,    -1,    24,   263,    -1,   364,   361,   264,    -1,
	367,   366,    -1,    -1,   305,    -1,   268,    -1,   269,    -1,
	33,    -1,   368,   263,   366,   264,    -1,   372,   370,    -1,
	-1,    66,    -1,   371,   256,    -1,   125,   240,    -1,   126,
	240,    -1,   121,    -1,   373,   263,   370,   264,    -1,   380,
	375,    -1,    -1,   131,    -1,   132,    -1,   133,    -1,   160,
	-1,   172,    19,    -1,   172,   314,    -1,   172,   220,    -1,
	130,    19,    -1,   130,   327,    -1,   130,   220,    -1,   100,
	19,    -1,   100,   416,    -1,   100,   220,    -1,   101,    19,
	-1,   101,   493,    -1,   101,   220,    -1,   102,   240,    -1,
	127,   240,    -1,   122,   240,    -1,   104,   242,    -1,   376,
	252,    -1,   103,   240,    -1,   377,   252,    -1,   378,   252,
	-1,   379,   252,    -1,   105,   240,    -1,    34,    -1,   381,
	263,   375,   264,    -1,   384,   383,    -1,    -1,   172,    19,
	-1,   172,   314,    -1,   172,   220,    -1,   130,    19,    -1,
	130,   327,    -1,   130,   220,    -1,   103,   240,    -1,   376,
	252,    -1,   377,   252,    -1,    35,   263,    -1,   385,   383,
	264,    -1,   389,   387,    -1,    -1,    66,    -1,   388,   256,
	-1,   268,    -1,   269,    -1,    29,    -1,   390,   263,   387,
	264,    -1,   395,   392,    -1,    -1,   177,    -1,   180,    -1,
	393,   254,    -1,   178,   248,    -1,   394,   238,    -1,   394,
	222,   229,   223,    -1,    37,    -1,   396,   263,   392,   264,
	-1,   399,   398,    -1,    -1,    99,   242,    -1,   181,   244,
	-1,   183,   244,    -1,   184,   242,    -1,   182,   244,    -1,
	185,   242,    -1,    38,    -1,   400,   263,   398,   264,    -1,
	404,   402,    -1,    -1,    66,    -1,    70,   240,    -1,    75,
	242,    -1,    71,   243,    -1,    72,   243,    -1,   403,   256,
	-1,   125,   240,    -1,   126,   240,    -1,    30,    -1,   405,
	263,   402,   264,    -1,   410,   407,    -1,    -1,    76,    -1,
	168,    -1,   408,   254,    -1,   161,   240,    -1,    75,   242,
	-1,   409,   256,    -1,    98,   242,    -1,    31,    -1,   411,
	263,   407,   264,    -1,   414,   413,    -1,    -1,   186,   260,
	-1,    39,    -1,   415,   263,   413,   264,    -1,   418,   417,
	-1,    -1,   316,   254,    -1,   317,   260,    -1,   221,   248,
	-1,    57,    -1,   419,   263,   417,   264,    -1,   422,   421,
	-1,    -1,   316,   254,    -1,   317,   262,    -1,   221,   245,
	-1,    58,    -1,   423,   263,   421,   264,    -1,   427,   425,
	-1,    -1,   192,    -1,   426,   222,   246,   223,    -1,   125,
	240,    -1,   126,   240,    -1,    32,    -1,   428,   263,   425,
	264,    -1,   431,   430,    -1,    -1,    90,   240,    -1,    92,
	240,    -1,   134,   247,    -1,   135,   247,    -1,    95,   248,
	-1,    62,    -1,   432,   263,   430,   264,    -1,   435,   434,
	-1,    -1,    99,   242,    -1,   136,   248,    -1,   172,   244,
	-1,   171,   242,    -1,   189,   248,    -1,   170,   240,    -1,
	169,   242,    -1,    59,    -1,   436,   263,   434,   264,    -1,
	439,   438,    -1,    -1,   172,    19,    -1,   172,   314,    -1,
	172,   220,    -1,   130,    19,    -1,   130,   327,    -1,   130,
	220,    -1,    60,    -1,   440,   263,   438,   264,    -1,   443,
	442,    -1,    -1,   316,   254,    -1,   317,   260,    -1,   221,
	248,    -1,    40,    -1,   444,   263,   442,   264,    -1,   447,
	446,    -1,    -1,   178,   248,    -1,   174,   248,    -1,    92,
	240,    -1,    41,    -1,   448,   263,   446,   264,    -1,   451,
	450,    -1,    -1,   316,   254,    -1,   317,   254,    -1,   221,
	247,    -1,    42,    -1,   452,   263,   450,   264,    -1,   456,
	454,    -1,    -1,    66,    -1,   455,   256,    -1,   139,   240,
	-1,   140,   240,    -1,   218,   195,     6,    -1,   218,   196,
	6,    -1,   218,   197,     6,    -1,   218,   198,     6,    -1,
	218,   199,     6,    -1,   218,   201,     6,    -1,   218,   202,
	6,    -1,   218,   203,     6,    -1,   218,   204,     6,    -1,
	218,   205,     6,    -1,   218,   207,     6,    -1,   218,   208,
	6,    -1,   218,   209,     6,    -1,   218,   210,     6,    -1,
	218,   212,     6,    -1,   218,   214,     6,    -1,   218,   215,
	6,    -1,   218,   216,     6,    -1,   219,   195,     6,    -1,
	219,   196,     6,    -1,   219,   197,     6,    -1,   219,   198,
	6,    -1,   219,   199,     6,    -1,   219,   201,     6,    -1,
	219,   202,     6,    -1,   219,   203,     6,    -1,   219,   204,
	6,    -1,   219,   205,     6,    -1,   219,   207,     6,    -1,
	219,   208,     6,    -1,   219,   209,     6,    -1,   219,   210,
	6,    -1,   219,   212,     6,    -1,   219,   214,     6,    -1,
	219,   215,     6,    -1,   219,   216,     6,    -1,   217,   195,
	6,   240,    -1,   217,   196,     6,   242,    -1,   217,   197,
	6,   239,    -1,   217,   198,     6,   243,    -1,   217,   199,
	6,   245,    -1,   217,   200,     6,    19,    -1,   217,   200,
	6,   220,     6,    -1,   217,   201,     6,   244,    -1,   217,
	203,     6,   241,    -1,   217,   204,     6,   247,    -1,   217,
	205,     6,   248,    -1,    43,    -1,   457,   263,   454,   264,
	-1,   460,   459,    -1,    -1,   137,    19,    -1,   137,   276,
	-1,   137,   220,    -1,   138,    19,    -1,   138,   233,    -1,
	138,   220,    -1,    44,    -1,   461,   263,   459,   264,    -1,
	464,   463,    -1,    -1,   173,   248,    -1,   171,   242,    -1,
	189,   248,    -1,   141,   242,    -1,   143,   242,    -1,   142,
	242,    -1,   144,   242,    -1,   145,   242,    -1,   146,    19,
	-1,   146,   281,    -1,   146,   406,    -1,   146,   220,    -1,
	147,   240,    -1,    45,    -1,   465,   263,   463,   264,    -1,
	468,   467,    -1,    -1,   169,   242,    -1,    61,    -1,   469,
	263,   467,   264,    -1,   472,   471,    -1,    -1,    90,   240,
	-1,    92,   240,    -1,    95,   245,    -1,    47,    -1,   473,
	263,   471,   264,    -1,   476,   475,    -1,    -1,    99,   242,
	-1,   136,   248,    -1,   148,   242,    -1,   172,   244,    -1,
	190,   242,    -1,   173,   248,    -1,   171,   242,    -1,   189,
	248,    -1,   170,   240,    -1,   169,   242,    -1,    46,    -1,
	477,   263,   475,   264,    -1,   481,   479,    -1,    -1,   149,
	-1,   480,   238,    -1,   480,   222,   229,   223,    -1,   150,
	239,    -1,    52,    -1,   482,   263,   479,   264,    -1,   487,
	484,    -1,    -1,   166,    -1,   152,    -1,   485,   256,    -1,
	151,    19,    -1,   151,   365,    -1,   151,   220,    -1,   486,
	254,    -1,   153,   242,    -1,    48,    -1,   488,   263,   484,
	264,    -1,   491,   490,    -1,    -1,   165,   258,    -1,    49,
	-1,   492,   263,   490,   264,    -1,   495,   494,    -1,    -1,
	178,   247,    -1,   154,   242,    -1,   155,   247,    -1,   179,
	247,    -1,    50,    -1,   496,   263,   494,   264,    -1,   499,
	498,    -1,    -1,   156,   243,    -1,    92,   240,    -1,    70,
	240,    -1,    71,   243,    -1,    72,   243,    -1,    51,    -1,
	500,   263,   498,   264,    -1,   503,   502,    -1,    -1,    92,
	240,    -1,    53,    -1,   504,   263,   502,   264,    -1,   507,
	506,    -1,    -1,   305,    -1,   178,   248,    -1,   154,   245,
	-1,   155,   248,    -1,   193,   245,    -1,   179,   248,    -1,
	268,    -1,   269,    -1,    63,    -1,   508,   263,   506,   264,
	-1,   511,   510,    -1,    -1,   157,   242,    -1,   158,   240,
	-1,   188,   245,    -1,   187,   248,    -1,   194,   241,    -1,
	54,    -1,   512,   263,   510,   264,    -1,   515,   514,    -1,
	-1,   178,   248,    -1,    92,   240,    -1,   174,   248,    -1,
	55,    -1,   516,   263,   514,   264,    -1,   519,   517,    -1,
	-1,    36,    -1,   518,   256,    -1,   159,   241,    -1,    56,
	-1,   520,   263,   517,   264,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
	0,   108,   108,   109,   110,   114,   115,   119,   120,   121,
	122,   123,   124,   125,   126,   130,   131,   132,   133,   134,
	135,   139,   140,   141,   142,   143,   144,   145,   149,   150,
	151,   152,   153,   154,   155,   156,   157,   158,   162,   163,
	164,   165,   166,   167,   171,   172,   173,   177,   178,   179,
	180,   181,   182,   186,   187,   188,   189,   193,   194,   195,
	196,   197,   198,   199,   200,   204,   211,   215,   222,   226,
	234,   235,   239,   249,   260,   261,   279,   288,   298,   299,
	300,   301,   305,   306,   310,   311,   312,   313,   317,   318,
	323,   324,   325,   326,   330,   331,   335,   336,   337,   338,
	342,   343,   347,   348,   349,   350,   354,   355,   359,   360,
	361,   362,   366,   367,   371,   372,   373,   374,   378,   379,
	383,   387,   388,   398,   399,   403,   410,   417,   424,   431,
	432,   437,   441,   445,   446,   450,   460,   475,   476,   480,
	481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
	494,   504,   519,   520,   524,   531,   535,   539,   543,   547,
	551,   558,   568,   583,   584,   588,   595,   602,   609,   616,
	623,   630,   637,   644,   651,   658,   662,   666,   670,   674,
	678,   682,   686,   690,   694,   701,   711,   726,   727,   731,
	732,   736,   737,   741,   751,   766,   767,   771,   778,   788,
	803,   804,   808,   809,   819,   820,   824,   831,   832,   836,
	837,   838,   839,   840,   847,   857,   872,   873,   877,   881,
	891,   906,   907,   911,   918,   925,   929,   936,   946,   961,
	962,   966,   970,   974,   978,   985,   995,  1010,  1011,  1015,
	1025,  1040,  1041,  1045,  1049,  1056,  1066,  1081,  1082,  1086,
	1090,  1094,  1098,  1102,  1109,  1119,  1134,  1135,  1139,  1143,
	1147,  1151,  1155,  1159,  1167,  1177,  1192,  1193,  1197,  1201,
	1205,  1209,  1213,  1220,  1230,  1245,  1246,  1250,  1258,  1259,
	1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1271,  1275,
	1279,  1283,  1287,  1291,  1295,  1299,  1303,  1310,  1320,  1335,
	1336,  1340,  1347,  1354,  1361,  1368,  1372,  1376,  1380,  1384,
	1388,  1392,  1396,  1400,  1404,  1411,  1421,  1436,  1437,  1441,
	1445,  1449,  1456,  1466,  1481,  1482,  1486,  1493,  1497,  1501,
	1505,  1509,  1513,  1517,  1521,  1525,  1532,  1542,  1557,  1558,
	1562,  1563,  1564,  1568,  1578,  1593,  1594,  1598,  1605,  1609,
	1613,  1620,  1630,  1645,  1646,  1650,  1657,  1664,  1671,  1678,
	1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
	1689,  1690,  1694,  1698,  1702,  1706,  1710,  1714,  1718,  1722,
	1726,  1733,  1743,  1758,  1759,  1763,  1764,  1765,  1766,  1767,
	1768,  1769,  1773,  1777,  1784,  1794,  1809,  1810,  1814,  1821,
	1825,  1826,  1830,  1840,  1855,  1856,  1860,  1868,  1875,  1879,
	1883,  1887,  1894,  1904,  1919,  1920,  1924,  1928,  1932,  1936,
	1940,  1944,  1951,  1961,  1976,  1977,  1981,  1988,  1992,  1996,
	2000,  2004,  2008,  2012,  2019,  2029,  2044,  2045,  2049,  2056,
	2063,  2067,  2071,  2075,  2079,  2086,  2096,  2111,  2112,  2116,
	2120,  2130,  2145,  2146,  2150,  2154,  2158,  2164,  2174,  2189,
	2190,  2194,  2198,  2202,  2208,  2218,  2233,  2234,  2238,  2245,
	2249,  2253,  2260,  2270,  2285,  2286,  2290,  2294,  2298,  2302,
	2306,  2313,  2323,  2339,  2340,  2344,  2348,  2352,  2356,  2360,
	2364,  2368,  2375,  2385,  2400,  2401,  2405,  2406,  2407,  2408,
	2409,  2410,  2415,  2425,  2440,  2441,  2445,  2449,  2453,  2459,
	2469,  2484,  2485,  2489,  2493,  2497,  2504,  2514,  2529,  2530,
	2534,  2538,  2542,  2548,  2558,  2573,  2574,  2578,  2585,  2589,
	2593,  2602,  2608,  2614,  2620,  2626,  2640,  2646,  2652,  2658,
	2664,  2675,  2681,  2687,  2693,  2707,  2713,  2719,  2725,  2736,
	2742,  2748,  2754,  2760,  2774,  2780,  2786,  2792,  2798,  2809,
	2815,  2821,  2827,  2841,  2847,  2853,  2859,  2870,  2876,  2882,
	2888,  2894,  2901,  2908,  2916,  2930,  2936,  2942,  2952,  2962,
	2978,  2979,  2983,  2984,  2985,  2986,  2987,  2988,  2992,  3002,
	3017,  3018,  3022,  3026,  3030,  3034,  3038,  3042,  3046,  3050,
	3054,  3055,  3056,  3057,  3058,  3065,  3075,  3090,  3091,  3095,
	3102,  3112,  3127,  3128,  3132,  3136,  3140,  3147,  3157,  3172,
	3173,  3177,  3181,  3185,  3189,  3193,  3197,  3201,  3205,  3209,
	3213,  3220,  3230,  3245,  3246,  3250,  3257,  3261,  3265,  3273,
	3283,  3298,  3299,  3303,  3310,  3317,  3321,  3322,  3323,  3324,
	3328,  3336,  3346,  3361,  3362,  3366,  3371,  3381,  3396,  3397,
	3401,  3405,  3409,  3413,  3421,  3431,  3446,  3447,  3451,  3455,
	3459,  3463,  3467,  3475,  3485,  3500,  3501,  3505,  3512,  3522,
	3537,  3538,  3542,  3543,  3547,  3551,  3555,  3559,  3563,  3564,
	3568,  3578,  3593,  3594,  3598,  3602,  3606,  3610,  3614,  3621,
	3631,  3646,  3647,  3651,  3655,  3659,  3666,  3676,  3691,  3692,
	3696,  3703,  3707,  3714,  3724
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
	"$end", "error", "$undefined", "NUMBER", "FLOAT", "STRING", "NAME",
	"ANCHOR", "APPEARANCE", "AUDIOCLIP", "BACKGROUND", "BILLBOARD", "BOX",
	"COLLISION", "COLOR", "COLOR_INTERP", "COORDINATE", "COORDINATE_INTERP",
	"CYLINDER_SENSOR", "NULL_STRING", "CONE", "CUBE", "CYLINDER",
	"DIRECTIONALLIGHT", "FONTSTYLE", "ERROR", "EXTRUSION", "ELEVATION_GRID",
	"FOG", "INLINE", "MOVIE_TEXTURE", "NAVIGATION_INFO", "PIXEL_TEXTURE",
	"GROUP", "INDEXEDFACESET", "INDEXEDLINESET", "S_INFO", "LOD",
	"MATERIAL", "NORMAL", "POSITION_INTERP", "PROXIMITY_SENSOR",
	"SCALAR_INTERP", "SCRIPT", "SHAPE", "SOUND", "SPOTLIGHT",
	"SPHERE_SENSOR", "TEXT", "TEXTURE_COORDINATE", "TEXTURE_TRANSFORM",
	"TIME_SENSOR", "SWITCH", "TOUCH_SENSOR", "VIEWPOINT",
	"VISIBILITY_SENSOR", "WORLD_INFO", "NORMAL_INTERP",
	"ORIENTATION_INTERP", "POINTLIGHT", "POINTSET", "SPHERE",
	"PLANE_SENSOR", "TRANSFORM", "S_CHILDREN", "S_PARAMETER", "S_URL",
	"S_MATERIAL", "S_TEXTURETRANSFORM", "S_TEXTURE", "S_LOOP",
	"S_STARTTIME", "S_STOPTIME", "S_GROUNDANGLE", "S_GROUNDCOLOR",
	"S_SPEED", "S_AVATAR_SIZE", "S_BACKURL", "S_BOTTOMURL", "S_FRONTURL",
	"S_LEFTURL", "S_RIGHTURL", "S_TOPURL", "S_SKYANGLE", "S_SKYCOLOR",
	"S_AXIS_OF_ROTATION", "S_COLLIDE", "S_COLLIDETIME", "S_PROXY", "S_SIDE",
	"S_AUTO_OFFSET", "S_DISK_ANGLE", "S_ENABLED", "S_MAX_ANGLE",
	"S_MIN_ANGLE", "S_OFFSET", "S_BBOXSIZE", "S_BBOXCENTER",
	"S_VISIBILITY_LIMIT", "S_AMBIENT_INTENSITY", "S_NORMAL", "S_TEXCOORD",
	"S_CCW", "S_COLOR_PER_VERTEX", "S_CREASE_ANGLE", "S_NORMAL_PER_VERTEX",
	"S_XDIMENSION", "S_XSPACING", "S_ZDIMENSION", "S_ZSPACING",
	"S_BEGIN_CAP", "S_CROSS_SECTION", "S_END_CAP", "S_SPINE", "S_FOG_TYPE",
	"S_VISIBILITY_RANGE", "S_HORIZONTAL", "S_JUSTIFY", "S_LANGUAGE",
	"S_LEFT2RIGHT", "S_TOP2BOTTOM", "IMAGE_TEXTURE", "S_SOLID", "S_KEY",
	"S_KEYVALUE", "S_REPEAT_S", "S_REPEAT_T", "S_CONVEX", "S_BOTTOM",
	"S_PICTH", "S_COORD", "S_COLOR_INDEX", "S_COORD_INDEX",
	"S_NORMAL_INDEX", "S_MAX_POSITION", "S_MIN_POSITION", "S_ATTENUATION",
	"S_APPEARANCE", "S_GEOMETRY", "S_DIRECT_OUTPUT", "S_MUST_EVALUATE",
	"S_MAX_BACK", "S_MIN_BACK", "S_MAX_FRONT", "S_MIN_FRONT", "S_PRIORITY",
	"S_SOURCE", "S_SPATIALIZE", "S_BERM_WIDTH", "S_CHOICE", "S_WHICHCHOICE",
	"S_FONTSTYLE", "S_LENGTH", "S_MAX_EXTENT", "S_ROTATION", "S_SCALE",
	"S_CYCLE_INTERVAL", "S_FIELD_OF_VIEW", "S_JUMP", "S_TITLE",
	"S_TEXCOORD_INDEX", "S_HEADLIGHT", "S_TOP", "S_BOTTOMRADIUS",
	"S_HEIGHT", "S_POINT", "S_STRING", "S_SPACING", "S_TYPE", "S_RADIUS",
	"S_ON", "S_INTENSITY", "S_COLOR", "S_DIRECTION", "S_SIZE", "S_FAMILY",
	"S_STYLE", "S_RANGE", "S_CENTER", "S_TRANSLATION", "S_LEVEL",
	"S_DIFFUSECOLOR", "S_SPECULARCOLOR", "S_EMISSIVECOLOR", "S_SHININESS",
	"S_TRANSPARENCY", "S_VECTOR", "S_POSITION", "S_ORIENTATION",
	"S_LOCATION", "S_CUTOFFANGLE", "S_WHICHCHILD", "S_IMAGE",
	"S_SCALEORIENTATION", "S_DESCRIPTION", "SFBOOL", "SFFLOAT", "SFINT32",
	"SFTIME", "SFROTATION", "SFNODE", "SFCOLOR", "SFIMAGE", "SFSTRING",
	"SFVEC2F", "SFVEC3F", "MFBOOL", "MFFLOAT", "MFINT32", "MFTIME",
	"MFROTATION", "MFNODE", "MFCOLOR", "MFIMAGE", "MFSTRING", "MFVEC2F",
	"MFVEC3F", "FIELD", "EVENTIN", "EVENTOUT", "USE", "S_VALUE_CHANGED",
	"'['", "']'", "','", "'{'", "'}'", "$accept", "Vrml", "VrmlNodes",
	"GroupingNode", "InterpolatorNode", "SensorNode", "GeometryNode",
	"GeometryInfoNode", "LightNode", "CommonNode", "BindableNode", "SFNode",
	"SFInt32", "SFBool", "SFString", "SFFloat", "SFTime", "SFColor",
	"SFRotation", "SFImageList", "SFVec2f", "SFVec3f", "SFColorList",
	"MFColor", "SFInt32List", "MFInt32", "SFFloatList", "MFFloat",
	"SFStringList", "MFString", "SFVec2fList", "MFVec2f", "SFVec3fList",
	"MFVec3f", "SFRotationList", "MFRotation", "NodeBegin", "NodeEnd",
	"AnchorElements", "AnchorElementParameterBegin",
	"AnchorElementURLBegin", "bboxCenter", "bboxSize", "AnchorElement",
	"AnchorBegin", "Anchor", "AppearanceNodes", "AppearanceNode",
	"AppearanceBegin", "Appearance", "AudioClipElements", "AudioClipURL",
	"AudioClipElement", "AudioClipBegin", "AudioClip", "BackGroundElements",
	"BackGroundBackURL", "BackGroundBottomURL", "BackGroundFrontURL",
	"BackGroundLeftURL", "BackGroundRightURL", "BackGroundTopURL",
	"BackGroundGroundAngle", "BackGroundGroundColor", "BackGroundSkyAngle",
	"BackGroundSkyColor", "BackGroundElement", "BackgroundBegin",
	"Background", "BillboardElements", "BillboardElement", "BillboardBegin",
	"Billboard", "BoxElements", "BoxElement", "BoxBegin", "Box",
	"childrenElements", "children", "CollisionElements",
	"CollisionElementProxyBegin", "CollisionElement", "CollisionBegin",
	"Collision", "ColorElements", "ColorElement", "ColorBegin", "Color",
	"ColorInterpElements", "InterpolateKey", "InterporlateKeyValue",
	"ColorInterpElement", "ColorInterpBegin", "ColorInterp", "ConeElements",
	"ConeElement", "ConeBegin", "Cone", "CoordinateElements",
	"CoordinateBegin", "Coordinate", "CoordinateInterpElements",
	"CoordinateInterpElement", "CoordinateInterpBegin", "CoordinateInterp",
	"CylinderElements", "CylinderElement", "CylinderBegin", "Cylinder",
	"CylinderSensorElements", "CylinderSensorElement",
	"CylinderSensorBegin", "CylinderSensor", "DirLightElements",
	"DirLightElement", "DirLightBegin", "DirLight", "ElevationGridElements",
	"ElevationGridHeight", "ElevationGridElement", "ElevationGridBegin",
	"ElevationGrid", "ExtrusionElements", "ExtrusionCrossSection",
	"ExtrusionOrientation", "ExtrusionScale", "ExtrusionSpine",
	"ExtrusionElement", "ExtrusionBegin", "Extrusion", "FogElements",
	"FogElement", "FogBegin", "Fog", "FontStyleElements",
	"FontStyleJustify", "FontStyleElement", "FontStyleBegin", "FontStyle",
	"GroupElements", "GroupElement", "GroupBegin", "Group",
	"ImgTexElements", "ImgTexURL", "ImgTexElement", "ImageTextureBegin",
	"ImageTexture", "IdxFacesetElements", "ColorIndex", "CoordIndex",
	"NormalIndex", "TextureIndex", "IdxFacesetElement", "IdxFacesetBegin",
	"IdxFaceset", "IdxLinesetElements", "IdxLinesetElement",
	"IdxLinesetBegin", "IdxLineset", "InlineElements", "InlineURL",
	"InlineElement", "InlineBegin", "Inline", "LodElements", "LodRange",
	"LodLevel", "LodElement", "LodBegin", "Lod", "MaterialElements",
	"MaterialElement", "MaterialBegin", "Material", "MovieTextureElements",
	"MovieTextureURL", "MovieTextureElement", "MovieTextureBegin",
	"MovieTexture", "NavigationInfoElements", "NavigationInfoAvatarSize",
	"NavigationInfoType", "NavigationInfoElement", "NavigationInfoBegin",
	"NavigationInfo", "NormalElements", "NormalElement", "NormalBegin",
	"Normal", "NormalInterpElements", "NormalInterpElement",
	"NormalInterpBegin", "NormalInterp", "OrientationInterpElements",
	"OrientationInterpElement", "OrientationInterpBegin",
	"OrientationInterp", "PixelTextureElements", "PixelTextureImage",
	"PixelTextureElement", "PixelTextureBegin", "PixelTexture",
	"PlaneSensorElements", "PlaneSensorElement", "PlaneSensorBegin",
	"PlaneSensor", "PointLightNodes", "PointLightNode", "PointLightBegin",
	"PointLight", "PointsetElements", "PointsetElement", "PointsetBegin",
	"Pointset", "PositionInterpElements", "PositionInterpElement",
	"PositionInterpBegin", "PositionInterp", "ProximitySensorElements",
	"ProximitySensorElement", "ProximitySensorBegin", "ProximitySensor",
	"ScalarInterpElements", "ScalarInterpElement", "ScalarInterpBegin",
	"ScalarInterp", "ScriptElements", "ScriptURL", "ScriptElement",
	"ScriptBegin", "Script", "SharpElements", "SharpElement", "ShapeBegin",
	"Shape", "SoundElements", "SoundElement", "SoundBegin", "Sound",
	"SphereElements", "SphereElement", "SphereBegin", "Sphere",
	"SphereSensorElements", "SphereSensorElement", "SphereSensorBegin",
	"SphereSensor", "SpotLightElements", "SpotLightElement",
	"SpotLightBegin", "SpotLight", "SwitchElements", "SwitchChoice",
	"SwitchElement", "SwitchBegin", "Switch", "TextElements", "TextString",
	"TextLength", "TextElement", "TextBegin", "Text", "TexCoordElements",
	"TexCoordElement", "TexCoordBegin", "TexCoordinate",
	"TextureTransformElements", "TextureTransformElement",
	"TexTransformBegin", "TexTransform", "TimeSensorElements",
	"TimeSensorElement", "TimeSensorBegin", "TimeSensor",
	"TouchSensorElements", "TouchSensorElement", "TouchSensorBegin",
	"TouchSensor", "TransformElements", "TransformElement",
	"TransformBegin", "Transform", "ViewpointElements", "ViewpointElement",
	"ViewpointBegin", "Viewpoint", "VisibilitySensors", "VisibilitySensor",
	"VisibilitySensorBegine", "WorldInfoElements", "WorldInfoInfo",
	"WorldInfoElement", "WorldInfoBegin", "WorldInfo", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
	0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
	265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
	275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
	285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
	295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
	305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
	315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
	325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
	335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
	345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
	355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
	365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
	375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
	385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
	395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
	405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
	415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
	425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
	435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
	445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
	455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
	465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
	475,   476,    91,    93,    44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
	0,   227,   228,   228,   228,   229,   229,   230,   230,   230,
	230,   230,   230,   230,   230,   231,   231,   231,   231,   231,
	231,   232,   232,   232,   232,   232,   232,   232,   233,   233,
	233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
	234,   234,   234,   234,   235,   235,   235,   236,   236,   236,
	236,   236,   236,   237,   237,   237,   237,   238,   238,   238,
	238,   238,   238,   238,   238,   239,   240,   241,   242,   242,
	243,   243,   244,   245,   246,   246,   247,   248,   249,   249,
	249,   249,   250,   250,   251,   251,   251,   251,   252,   252,
	253,   253,   253,   253,   254,   254,   255,   255,   255,   255,
	256,   256,   257,   257,   257,   257,   258,   258,   259,   259,
	259,   259,   260,   260,   261,   261,   261,   261,   262,   262,
	263,   264,   264,   265,   265,   266,   267,   268,   269,   270,
	270,   270,   270,   270,   270,   271,   272,   273,   273,   274,
	274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
	275,   276,   277,   277,   278,   279,   279,   279,   279,   279,
	279,   280,   281,   282,   282,   283,   284,   285,   286,   287,
	288,   289,   290,   291,   292,   293,   293,   293,   293,   293,
	293,   293,   293,   293,   293,   294,   295,   296,   296,   297,
	297,   297,   297,   298,   299,   300,   300,   301,   302,   303,
	304,   304,   305,   305,   306,   306,   307,   308,   308,   308,
	308,   308,   308,   308,   309,   310,   311,   311,   312,   313,
	314,   315,   315,   316,   317,   318,   318,   319,   320,   321,
	321,   322,   322,   322,   322,   323,   324,   325,   325,   326,
	327,   328,   328,   329,   329,   330,   331,   332,   332,   333,
	333,   333,   333,   333,   334,   335,   336,   336,   337,   337,
	337,   337,   337,   337,   338,   339,   340,   340,   341,   341,
	341,   341,   341,   342,   343,   344,   344,   345,   346,   346,
	346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
	346,   346,   346,   346,   346,   346,   346,   347,   348,   349,
	349,   350,   351,   352,   353,   354,   354,   354,   354,   354,
	354,   354,   354,   354,   354,   355,   356,   357,   357,   358,
	358,   358,   359,   360,   361,   361,   362,   363,   363,   363,
	363,   363,   363,   363,   363,   363,   364,   365,   366,   366,
	367,   367,   367,   368,   369,   370,   370,   371,   372,   372,
	372,   373,   374,   375,   375,   376,   377,   378,   379,   380,
	380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
	380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
	380,   381,   382,   383,   383,   384,   384,   384,   384,   384,
	384,   384,   384,   384,   385,   386,   387,   387,   388,   389,
	389,   389,   390,   391,   392,   392,   393,   394,   395,   395,
	395,   395,   396,   397,   398,   398,   399,   399,   399,   399,
	399,   399,   400,   401,   402,   402,   403,   404,   404,   404,
	404,   404,   404,   404,   405,   406,   407,   407,   408,   409,
	410,   410,   410,   410,   410,   411,   412,   413,   413,   414,
	415,   416,   417,   417,   418,   418,   418,   419,   420,   421,
	421,   422,   422,   422,   423,   424,   425,   425,   426,   427,
	427,   427,   428,   429,   430,   430,   431,   431,   431,   431,
	431,   432,   433,   434,   434,   435,   435,   435,   435,   435,
	435,   435,   436,   437,   438,   438,   439,   439,   439,   439,
	439,   439,   440,   441,   442,   442,   443,   443,   443,   444,
	445,   446,   446,   447,   447,   447,   448,   449,   450,   450,
	451,   451,   451,   452,   453,   454,   454,   455,   456,   456,
	456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
	456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
	456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
	456,   456,   456,   456,   456,   456,   456,   456,   456,   456,
	456,   456,   456,   456,   456,   456,   456,   456,   457,   458,
	459,   459,   460,   460,   460,   460,   460,   460,   461,   462,
	463,   463,   464,   464,   464,   464,   464,   464,   464,   464,
	464,   464,   464,   464,   464,   465,   466,   467,   467,   468,
	469,   470,   471,   471,   472,   472,   472,   473,   474,   475,
	475,   476,   476,   476,   476,   476,   476,   476,   476,   476,
	476,   477,   478,   479,   479,   480,   481,   481,   481,   482,
	483,   484,   484,   485,   486,   487,   487,   487,   487,   487,
	487,   488,   489,   490,   490,   491,   492,   493,   494,   494,
	495,   495,   495,   495,   496,   497,   498,   498,   499,   499,
	499,   499,   499,   500,   501,   502,   502,   503,   504,   505,
	506,   506,   507,   507,   507,   507,   507,   507,   507,   507,
	508,   509,   510,   510,   511,   511,   511,   511,   511,   512,
	513,   514,   514,   515,   515,   515,   516,   515,   517,   517,
	518,   519,   519,   520,   521
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
	0,     2,     1,     1,     1,     2,     0,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
	1,     1,     3,     4,     2,     0,     2,     3,     1,     2,
	2,     0,     1,     3,     1,     2,     2,     0,     1,     3,
	1,     2,     2,     0,     1,     3,     1,     2,     2,     0,
	1,     3,     1,     2,     2,     0,     1,     3,     1,     2,
	2,     0,     1,     3,     1,     2,     2,     0,     1,     3,
	1,     1,     2,     2,     0,     1,     1,     2,     2,     1,
	2,     2,     2,     1,     1,     1,     4,     2,     0,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	1,     4,     2,     0,     1,     2,     2,     2,     2,     2,
	2,     1,     4,     2,     0,     1,     1,     1,     1,     1,
	1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     1,     4,     2,     0,     1,
	2,     1,     1,     1,     4,     2,     0,     2,     1,     4,
	2,     0,     4,     2,     2,     0,     1,     1,     2,     1,
	1,     2,     2,     2,     1,     4,     2,     0,     2,     1,
	4,     2,     0,     1,     1,     2,     2,     1,     4,     2,
	0,     2,     2,     2,     2,     1,     4,     2,     0,     1,
	4,     2,     0,     2,     2,     1,     4,     2,     0,     2,
	2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
	2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
	2,     2,     2,     1,     4,     2,     0,     1,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     1,     4,     2,
	0,     1,     1,     1,     1,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     1,     4,     2,     0,     2,
	2,     2,     1,     4,     2,     0,     1,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     3,     2,     0,
	1,     1,     1,     1,     4,     2,     0,     1,     2,     2,
	2,     1,     4,     2,     0,     1,     1,     1,     1,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     1,     4,     2,     0,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     3,     2,     0,     1,     2,
	1,     1,     1,     4,     2,     0,     1,     1,     2,     2,
	2,     4,     1,     4,     2,     0,     2,     2,     2,     2,
	2,     2,     1,     4,     2,     0,     1,     2,     2,     2,
	2,     2,     2,     2,     1,     4,     2,     0,     1,     1,
	2,     2,     2,     2,     2,     1,     4,     2,     0,     2,
	1,     4,     2,     0,     2,     2,     2,     1,     4,     2,
	0,     2,     2,     2,     1,     4,     2,     0,     1,     4,
	2,     2,     1,     4,     2,     0,     2,     2,     2,     2,
	2,     1,     4,     2,     0,     2,     2,     2,     2,     2,
	2,     2,     1,     4,     2,     0,     2,     2,     2,     2,
	2,     2,     1,     4,     2,     0,     2,     2,     2,     1,
	4,     2,     0,     2,     2,     2,     1,     4,     2,     0,
	2,     2,     2,     1,     4,     2,     0,     1,     2,     2,
	2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
	3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
	3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
	3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
	4,     4,     4,     5,     4,     4,     4,     4,     1,     4,
	2,     0,     2,     2,     2,     2,     2,     2,     1,     4,
	2,     0,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     1,     4,     2,     0,     2,
	1,     4,     2,     0,     2,     2,     2,     1,     4,     2,
	0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     1,     4,     2,     0,     1,     2,     4,     2,     1,
	4,     2,     0,     1,     1,     2,     2,     2,     2,     2,
	2,     1,     4,     2,     0,     2,     1,     4,     2,     0,
	2,     2,     2,     2,     1,     4,     2,     0,     2,     2,
	2,     2,     2,     1,     4,     2,     0,     2,     1,     4,
	2,     0,     1,     2,     2,     2,     2,     2,     1,     1,
	1,     4,     2,     0,     2,     2,     2,     2,     2,     1,
	4,     2,     0,     2,     2,     2,     1,     4,     2,     0,
	1,     2,     2,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
	0,     3,   135,   150,   161,   185,   193,   214,   219,   227,
	239,   245,   264,   273,     0,     4,   322,   402,   445,   343,
	412,   422,   450,   509,   516,   523,   578,   588,   605,   631,
	617,   656,   673,   639,   678,   699,   706,   713,   457,   464,
	492,   481,   690,     0,     0,     0,    64,     0,     2,    62,
	60,    61,    63,    48,    57,    58,     6,     0,     7,     0,
	42,     0,    47,     0,    53,     0,     8,     0,     9,     0,
	38,     0,    15,     0,    39,     0,    16,     0,    21,     0,
	44,     0,    54,   325,    59,     0,    10,     0,    11,     0,
	12,     0,    43,     0,    55,     0,    40,     0,    17,     0,
	18,     0,    22,     0,    46,     0,    19,     0,    24,     0,
	20,     0,    49,     0,    50,     0,    51,     0,    23,     0,
	45,     0,    13,     0,    41,     0,    25,     0,    26,     0,
	14,     0,    56,    27,     0,     0,    52,   120,   336,    66,
	704,    69,    68,     0,   705,   703,     1,     5,   124,   138,
	153,   164,   188,   205,   217,   222,   238,   242,   257,   267,
	318,     0,   326,     0,     0,     0,     0,     0,     0,     0,
	0,     0,   325,   339,   397,   405,   415,   437,   448,   453,
	460,   475,   484,   505,   512,   519,   526,   581,   591,   613,
	620,   634,   654,   667,   676,   681,   693,   702,   709,     0,
	0,   125,   126,     0,     0,     0,     0,     0,     0,   133,
	134,   124,   129,     0,     0,     0,     0,   138,   154,     0,
	0,     0,     0,     0,     0,     0,   153,   171,   172,   165,
	166,   167,   168,   169,   170,   173,   174,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,   164,     0,
	191,   192,     0,   188,   189,     0,   206,   209,   210,   207,
	0,     0,   205,     0,     0,   217,   223,   224,     0,     0,
	0,   222,     0,     0,     0,     0,     0,   242,     0,     0,
	0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
	0,     0,   267,     0,     0,     0,     0,   318,   328,    67,
	330,   331,   335,   333,   332,   327,   334,   121,   337,    99,
	100,   329,   324,   341,   342,   340,     0,   339,   398,   400,
	401,     0,     0,   397,   406,     0,   407,     0,     0,     0,
	405,     0,     0,     0,     0,     0,     0,     0,   415,     0,
	438,     0,     0,   439,     0,     0,     0,   437,     0,     0,
	448,     0,     0,     0,     0,   453,     0,     0,     0,     0,
	460,     0,     0,     0,     0,     0,     0,   475,     0,     0,
	0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
	0,   505,     0,     0,     0,     0,   512,     0,     0,     0,
	0,   519,   527,     0,     0,     0,     0,     0,     0,     0,
	526,     0,     0,     0,   581,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,   591,     0,     0,     0,
	0,   613,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,   620,   635,     0,     0,     0,   634,     0,
	0,   654,     0,     0,     0,     0,     0,     0,   667,     0,
	0,   676,     0,     0,     0,     0,     0,   688,   689,   682,
	0,   681,     0,     0,     0,     0,     0,     0,   693,     0,
	702,   710,     0,     0,     0,   709,    77,   201,   203,   128,
	127,   130,   136,   131,   132,   123,   139,   141,   140,   147,
	664,   149,     0,   148,   142,   434,   472,   351,   146,     0,
	143,     0,   144,     0,   145,   151,   137,   156,    71,    70,
	158,   159,   157,   155,   162,   160,   152,   186,   177,   178,
	179,   180,   181,   182,    93,    94,   175,    81,     0,    82,
	176,   183,   184,   163,   190,   194,   187,   208,   212,   211,
	215,   213,   204,   218,   220,   216,   228,   225,   226,   221,
	111,   112,   237,   240,   243,   244,   246,   241,   258,   259,
	260,   261,   262,   263,   265,   256,   272,   268,   269,   270,
	271,   274,   266,   320,   321,   319,   323,   317,   122,    99,
	96,     0,   344,   338,   403,   399,   396,   409,   413,   408,
	6,   410,   404,   416,   417,   420,   418,   419,   421,   423,
	414,   442,   444,   441,   446,   440,   443,   436,   449,   451,
	447,   456,   454,   455,   458,   452,     0,   463,   461,   117,
	118,   462,   465,   459,   476,   477,   480,     0,   478,   479,
	482,   474,   485,   486,   491,   490,   488,   487,   489,   493,
	483,   508,   506,   507,   510,   504,   515,   514,   513,   517,
	511,   522,   520,   521,   524,   518,   529,   530,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,   579,   528,   525,   582,   584,   583,
	198,   585,   235,   254,   315,   297,   381,     0,   651,   502,
	610,   587,   586,     0,    28,     0,    29,     0,    30,     0,
	31,     0,    32,     0,    33,   384,    34,     0,    35,     0,
	36,     0,    37,   589,   580,   595,   597,   596,   598,   599,
	600,   603,   601,   602,   604,   593,   592,   594,   606,   590,
	614,   615,   616,   618,   612,   621,   622,   623,   630,   629,
	627,   624,   626,   628,   625,   632,   619,    65,   638,   640,
	6,   636,   633,   105,   106,   655,   657,   653,   670,   671,
	672,   669,   668,   674,   666,   677,   679,   675,   684,   685,
	683,   687,   686,   691,   680,   694,   695,   697,   696,   698,
	700,   692,   707,   701,   712,   714,   711,   708,   201,     0,
	659,   346,   425,   467,    93,    90,     0,    81,    78,     0,
	0,   111,   108,     0,    98,    97,   101,     0,     0,   117,
	114,     0,    76,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,   531,   532,   533,   534,   535,   536,   537,
	538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
	548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
	558,   559,   560,   561,   562,   563,   564,   565,   566,   394,
	196,   230,   248,   276,   300,   354,     0,     0,   355,   356,
	0,     0,     0,     0,   384,   495,   608,   642,     0,   105,
	102,     0,   200,   202,     0,     0,     0,     0,     0,   659,
	347,     0,     0,     0,     0,   346,   426,     0,     0,     0,
	0,     0,     0,     0,     0,   425,     0,     0,   468,     0,
	0,   467,    92,    91,    95,    80,    79,    83,    72,   110,
	109,   113,   411,     0,   116,   115,   119,   567,   568,   569,
	570,   571,   572,     0,   574,   575,   576,   577,     0,     0,
	196,     0,     0,     0,     0,     0,   230,     0,     0,     0,
	0,     0,     0,   248,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,   277,     0,     0,     0,   276,
	0,     0,     0,   301,     0,   304,     0,     0,   303,   302,
	0,     0,     0,     0,     0,   300,     0,     0,     0,     0,
	0,     0,     0,     0,     0,   357,   358,     0,     0,     0,
	0,     0,     0,   354,   391,   388,   390,   389,   385,   387,
	386,    87,    88,   392,   393,   395,   383,     0,     0,     0,
	495,     0,     0,   608,     0,   644,     0,   643,     0,     0,
	0,   642,   637,   104,   103,   107,   661,   662,   660,   663,
	665,   658,   349,   350,   352,   348,   345,   427,   429,   430,
	428,   432,   433,   435,   431,   424,   470,   471,   473,    75,
	466,    73,   573,   197,   199,   195,   231,   232,   233,   234,
	236,   229,   249,   250,   251,   253,   252,   255,   247,   281,
	283,   282,   284,   286,   285,   288,   291,   289,   292,   293,
	294,   295,   296,   290,   278,   280,   279,   298,   287,   275,
	306,   308,   305,   311,   309,   307,   316,   310,   312,   313,
	314,   299,   365,   367,   366,   368,   370,   369,   371,   376,
	374,   380,   373,   372,   362,   364,   363,   359,   361,   360,
	382,   375,   377,   378,   379,   353,    87,    84,     0,   499,
	501,   500,   496,   498,   497,   503,   494,   609,   611,   607,
	646,   648,   647,   650,   652,   645,   649,   641,    75,     0,
	86,    85,    89,    74,   469
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
	-1,    47,    48,    49,    50,    51,   722,    52,    53,    54,
	55,    56,  1042,   140,   310,   143,   510,   529,   840,  1189,
	784,   551,   829,   530,  1168,  1043,   826,   526,   581,   311,
	911,   785,   833,   552,   841,   621,   138,   308,   206,   207,
	208,   209,   210,   211,    57,    58,   216,   217,    59,    60,
	224,   225,   226,    61,    62,   237,   238,   239,   240,   241,
	242,   243,   244,   245,   246,   247,   248,    63,    64,   252,
	253,    65,    66,   969,   970,   723,   724,   819,   212,   260,
	261,   262,    67,    68,   264,   265,    69,    70,   268,   269,
	270,   271,    71,    72,   975,   976,   725,   726,   273,    73,
	74,   276,   277,    75,    76,   982,   983,   727,   728,   284,
	285,    77,    78,   291,   292,    79,    80,   997,   998,   999,
	729,   730,  1010,  1011,  1012,  1013,  1014,  1015,   731,   732,
	296,   297,    81,    82,   170,   171,   172,    83,    84,   316,
	317,    85,    86,   923,   924,   925,   499,   500,  1028,   901,
	902,  1031,  1032,  1033,   733,   734,   903,   904,   735,   736,
	321,   322,   323,    87,    88,   327,   328,   329,   330,    89,
	90,   337,   338,    91,    92,   933,   934,   935,   501,   502,
	344,   345,   346,   347,    93,    94,   349,   350,    95,    96,
	354,   355,    97,    98,   359,   360,    99,   100,   939,   940,
	941,   503,   504,   366,   367,   101,   102,   375,   376,   103,
	104,  1049,  1050,   737,   738,   380,   381,   105,   106,   385,
	386,   107,   108,   390,   391,   109,   110,   398,   399,   400,
	111,   112,   403,   404,   113,   114,   415,   416,   115,   116,
	1052,  1053,   739,   740,   420,   421,   117,   118,   432,   433,
	119,   120,   436,   437,   438,   121,   122,  1058,  1059,  1060,
	1061,   741,   742,   440,   441,   123,   124,   918,   919,   492,
	493,   447,   448,   125,   126,   450,   451,   127,   128,   460,
	461,   129,   130,   467,   468,   131,   132,   469,   133,   134,
	473,   474,   475,   135,   136
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -936
static const short yypact[] =
{
	1263,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -194,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,    36,   368,   368,  -936,    62,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,   864,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,   979,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -936,  -194,  -194,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,   368,  -936,  -936,  -936,  -936,   309,   294,
	351,  1039,    85,   538,   -67,   344,  -116,   344,   838,   383,
	263,    36,  -936,   109,    36,    36,   368,   368,   109,   109,
	-115,    20,   979,   128,   332,   238,   614,   305,   -63,   -50,
	75,   511,   480,   213,   149,   218,   148,   352,   660,   121,
	491,   355,   -31,   459,    60,   450,   269,   117,    31,   368,
	962,  -936,  -936,   368,   368,   109,  -115,    20,    20,  -936,
	-936,   309,  -936,    50,    90,   231,  -115,   294,  -936,    36,
	504,   504,   368,   109,  -115,    20,   351,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -115,    20,    20,
	20,    20,    20,    20,    49,    77,    49,    77,  1039,   368,
	-936,  -936,  -115,    85,  -936,    36,   123,  -936,  -936,  -936,
	-115,   864,   538,    77,  -115,   -67,  -936,  -936,  -115,    49,
	77,   344,    81,  -115,    49,    81,  -115,   344,    36,   368,
	36,   368,   368,   368,  -115,   838,   368,    36,   368,   368,
	368,  -115,   383,   109,   368,   368,  -115,   263,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,   -70,  -936,     5,
	-936,  -936,  -936,  -936,  -936,  -936,  -115,   128,  -936,  -936,
	-936,  -115,    20,   332,  -936,   368,  -936,  -115,    49,  1320,
	238,   368,   368,   368,   368,   368,   368,  -115,   614,   368,
	-936,   368,    36,  -936,  -115,    49,    20,   305,    81,  -115,
	-63,   368,    49,    81,  -115,   -50,   368,    49,    83,  -115,
	75,    36,    36,   368,   368,   368,  -115,   511,   368,   368,
	368,    36,   368,   368,   368,  -115,   480,   368,    49,    81,
	-115,   213,    36,   368,   368,  -115,   149,   368,    49,    49,
	-115,   218,  -936,    36,    36,  1304,  1247,  1277,  -115,    20,
	148,    28,   562,  -115,   352,   368,   368,   368,   368,   368,
	74,    36,   368,   368,   368,  -115,   660,    36,    36,   368,
	-115,   121,   368,   368,   368,   368,    36,   368,   368,   368,
	368,   368,  -115,   491,  -936,   153,  -115,  1377,   355,    86,
	-115,   -31,    36,   504,   504,    36,   504,  -115,   459,    36,
	-115,    60,   368,   368,   368,   368,   368,  -936,  -936,  -936,
	-115,   450,   368,    36,   368,   368,   109,  -115,   269,  -115,
	117,  -936,   109,  -115,    20,    31,  -936,   864,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -194,  -936,  -936,  -936,  -936,  -936,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,    19,  -936,  -936,    23,   368,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	29,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,     5,
	5,   -48,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	864,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,   368,  -936,  -936,    40,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,   368,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,   167,   171,
	174,   187,   189,   191,   198,   201,   214,   222,   230,   245,
	267,   287,   295,   310,   314,   328,   348,   350,   362,   378,
	387,   391,   394,   398,   418,   424,   427,   432,   437,   444,
	447,   449,   454,   458,   466,   482,   518,   522,   527,   530,
	533,   536,   542,   564,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -194,  -936,  -936,
	-936,  -936,  -936,  -194,  -936,  -194,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -194,  -936,    34,  -936,  -194,  -936,  -194,
	-936,  -194,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	864,  -936,  -936,    42,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,   864,     3,
	320,   265,   600,   220,    19,    19,    37,    23,    23,    46,
	368,    29,    29,   345,  -936,  -936,  -936,   354,   368,    40,
	40,   357,  -936,    36,   368,   153,   504,   368,   124,   368,
	109,   368,   368,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	409,   225,   395,   967,   595,   931,    36,    97,  -936,  -936,
	-1,    16,    16,  -115,    34,   -69,   439,   526,   364,    42,
	42,   388,  -936,  -936,   368,   368,   368,   368,  -115,   320,
	-936,    36,    36,  -115,    20,   265,  -936,    36,   504,   504,
	368,    36,    36,  -115,    20,   600,    36,    36,  -936,  -115,
	392,   220,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,   368,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,   607,  -936,  -936,  -936,  -936,   368,  -115,
	409,    36,    36,   368,   368,  -115,   225,    36,    36,    36,
	368,   368,  -115,   395,    -5,    52,    36,    36,   368,    36,
	153,   368,   153,   368,    36,  -936,    45,  -115,    49,   967,
	36,   368,    36,  -936,    36,  -936,    36,    36,  -936,  -936,
	-115,    86,    83,    86,    81,   595,   108,    80,    36,    36,
	368,    36,    36,    36,   101,  -936,  -936,    78,  -115,    16,
	16,    16,    16,   931,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,    13,  -936,  -936,  -936,  -936,  -936,   106,    93,  -115,
	-69,   368,  -115,   439,   127,  -936,   368,  -936,  -115,    20,
	49,   526,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,   153,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,    13,    13,   396,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,   153,   397,
	-936,  -936,  -936,  -936,  -936
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
	-936,  -936,   -47,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	-936,  -193,  -432,  -159,  -148,   113,  -213,  -278,  -321,  -570,
	-324,   -44,  -316,    59,  -650,  -681,  -263,  -204,   -13,   254,
	-337,  -935,  -237,  -271,  -241,  -391,  1118,  -158,   419,  -936,
	-936,  -123,   102,  -936,  -936,  -936,   414,  -936,  -936,   235,
	406,  -936,  -936,  -936,   232,   399,  -936,  -936,  -936,  -936,
	-936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,  -936,   401,
	-936,  -936,  -936,  -326,  -936,  -936,  -936,  -163,    15,   403,
	-936,  -936,  -936,  -936,   393,  -936,  -936,  -809,   385,   257,
	330,  -936,  -936,  -936,  -317,  -936,  -936,  -936,  -936,  -936,
	-869,   390,  -936,  -936,  -936,  -315,  -936,  -936,  -936,   389,
	-936,  -936,  -936,   381,  -936,  -936,  -936,  -323,  -936,  -936,
	-936,  -936,  -333,  -936,  -936,  -936,  -936,  -936,  -936,  -936,
	386,  -936,  -936,  -936,   514,  -936,  -936,  -936,  -367,   371,
	-936,  -936,  -936,  -236,  -936,  -936,  -936,  -936,  -340,  -871,
	-857,  -936,  -936,  -936,  -936,  -936,  -210,  -936,  -936,  -936,
	372,  -936,  -936,  -936,  -936,   366,  -936,  -936,  -936,  -936,
	-936,   360,  -936,  -936,   487,  -234,  -936,  -936,  -936,   293,
	363,  -936,  -936,  -936,  -936,  -936,   359,  -936,  -936,  -884,
	349,  -936,  -936,  -936,   358,  -936,  -936,  -936,  -229,  -936,
	-936,  -936,  -936,   347,  -936,  -936,  -936,   343,  -936,  -936,
	-936,  -330,  -936,  -936,  -936,   342,  -936,  -936,  -936,   338,
	-936,  -936,  -936,   336,  -936,  -936,  -936,   331,  -936,  -936,
	-936,  -936,   326,  -936,  -936,  -936,   322,  -936,  -936,  -936,
	-314,  -936,  -936,  -936,   315,  -936,  -936,  -936,   308,  -936,
	-936,  -936,   304,  -936,  -936,  -936,  -936,  -313,  -936,  -936,
	-936,  -936,  -936,   303,  -936,  -936,  -828,  -173,  -936,  -936,
	-936,   299,  -936,  -936,  -936,   298,  -936,  -936,  -936,   290,
	-936,  -936,  -936,   284,  -936,  -936,  -936,   283,  -185,  -936,
	279,  -936,  -936,  -936,  -936
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -7
static const short yytable[] =
{
	144,   145,   298,   778,   555,   301,   302,   478,   511,   147,
	299,   569,   470,     8,  1109,   300,   777,   575,  1038,   777,
	305,   306,   141,   142,  1029,   299,   141,   142,  1037,   250,
	257,   137,   141,   142,    22,   617,     3,   620,  1030,   139,
	628,   629,   531,   141,   142,   141,   142,   707,   482,   272,
	313,   319,   141,   142,   594,   595,   596,   481,   505,     8,
	507,  1047,   146,   651,  1124,   547,   514,   471,   541,   486,
	554,  1112,   457,   266,   267,   513,  1137,   608,  1139,   517,
	141,   142,   613,     4,   141,   142,   141,   142,    21,   141,
	142,  1040,     8,   750,   535,   637,   537,  1157,   762,  1145,
	1111,    31,   540,  1048,   495,   263,   544,     8,   643,   489,
	546,   307,  1172,    10,   299,   553,  1035,    10,   556,   558,
	1154,   560,    10,   348,   589,  1169,   564,  1142,   567,    31,
	250,   798,  1144,   571,   439,   802,   591,   896,   576,   257,
	490,   605,   538,   962,   808,   573,  1180,    22,   612,   200,
	771,    14,   449,   618,   578,  1156,   777,  1114,   582,   479,
	480,   580,  1029,   584,   897,   898,   899,   254,   259,   588,
	249,   351,    36,   843,   642,   836,  1030,   844,  1171,   599,
	845,   203,   204,   603,   652,   653,   604,  1126,   315,  1147,
	472,   609,   200,   846,   313,   847,   614,   848,   266,   267,
	319,   622,   624,   625,   849,   534,   900,   850,   630,    43,
	459,   417,   635,   418,   392,  1110,   419,   639,  1159,  1039,
	851,  1044,   644,   646,   203,   204,   913,   649,   852,   579,
	789,   790,   654,   792,   656,   657,   853,  1166,  1041,  1174,
	704,   382,   309,   824,   781,   743,   570,   827,   708,   828,
	494,   854,   754,   831,   251,   258,   199,   758,   760,   761,
	944,   495,   763,   496,   839,  1125,   909,   769,   254,   947,
	487,   524,  1113,   855,   775,   314,   320,   259,   779,   303,
	304,   587,   786,   788,   818,   470,   791,   393,   394,   793,
	795,    44,   796,   856,   751,    45,   356,   458,  1158,   527,
	1146,   857,   803,   550,   806,   619,   532,   611,   783,   810,
	491,   812,   476,  1173,   971,   815,   858,  1036,   809,   626,
	859,  1155,   543,   383,   814,   633,  1170,   384,  1143,   548,
	638,   920,   315,   641,   860,   512,   266,   267,   457,   647,
	648,   266,   267,   539,   963,   936,   937,  1181,  1161,  1162,
	1163,  1164,   497,   972,   861,   251,   862,   525,   528,   525,
	528,   213,   214,   215,   258,   395,   396,   397,   863,   756,
	757,   141,   142,   200,   201,   202,   528,   293,   294,   766,
	339,   340,   525,   528,   864,   772,   773,   525,   973,   974,
	921,   922,   559,   865,   561,   562,   563,   866,   318,   566,
	867,   568,   528,   341,   868,   203,   204,   574,   528,   799,
	800,   801,   938,   959,   274,   324,   325,   218,   326,   314,
	807,   219,   220,   221,   869,   320,   462,   463,   203,   204,
	870,   580,   580,   871,   377,   295,   352,   357,   872,   387,
	378,   525,   388,   873,   593,   528,   528,   528,   597,   598,
	874,   498,   601,   875,   602,   876,   464,   465,   525,   910,
	877,   483,   484,   466,   878,   525,   342,   266,   267,   616,
	525,   616,   879,   343,   914,   915,   459,   627,   627,   515,
	222,   632,   286,   634,   977,   636,   528,   275,   880,   401,
	402,   525,   518,   519,   520,   521,   522,   523,   916,   917,
	627,   525,   525,   205,   434,   435,   832,   508,   509,   353,
	358,   945,   946,   379,   200,   389,  1190,  1191,   745,   746,
	747,   748,   749,   978,   881,   755,   961,   966,   882,   442,
	443,   444,   616,   883,   274,   765,   884,   767,   768,   885,
	770,   528,   886,   837,   774,   223,   203,   204,   887,   828,
	828,   445,   627,   287,   288,   289,   290,   979,  1119,   980,
	1121,   942,   943,   458,   981,   616,   834,   835,   951,   616,
	888,   964,  1063,  1064,   710,   805,   585,   952,   616,   368,
	956,   711,   712,   968,   713,   910,   910,  1062,   714,   715,
	422,  1067,  1068,  1069,   949,   950,   716,   717,   954,   955,
	606,   361,   200,   362,   452,   453,   363,   275,  1051,  1167,
	718,  1065,   352,  1092,  1089,   446,   369,   357,  1193,  1192,
	1194,  1138,   719,   720,   255,   818,   256,   423,   454,   455,
	485,   506,   516,   960,   203,   204,   709,   825,   378,   424,
	528,   830,   752,   456,  1095,   364,   365,   533,   388,   370,
	371,   372,   373,   705,   536,   912,   549,  1188,   545,  1101,
	425,   426,   427,   428,   429,   542,   926,   557,  1108,   374,
	927,   928,   929,   572,   565,   930,  1129,  1054,  1055,  1056,
	430,   431,  1141,   577,   957,   353,   312,  1182,   583,  1076,
	358,   620,  1057,  1165,  1046,   586,   592,  1000,   600,  1001,
	488,  1085,   965,   753,   615,  1002,  1003,  1004,  1005,   610,
	607,   379,  1090,   331,   631,  1078,  1079,  1006,   623,   640,
	1176,   389,  1007,   645,   650,   931,   932,   655,   816,   838,
	744,   706,   616,   908,  1167,  1167,   764,  1034,   759,  1179,
	842,   776,   782,  1140,   787,  1045,  1071,   794,  1187,   797,
	1008,   804,   811,   813,   817,     0,  1188,     0,     0,     0,
	1070,     0,  1072,  1073,     0,  1074,     0,     0,  1077,     0,
	0,     0,  1081,  1082,     0,  1083,     0,  1086,  1087,     0,
	0,  1088,   721,  1009,     0,     0,     0,   832,   832,     0,
	0,     0,     0,     0,  1128,   332,   333,   334,   335,   336,
	0,   405,   406,   407,   408,   409,   410,   411,   967,     0,
	0,  1094,  1096,  1097,     0,     0,     0,  1100,  1102,  1103,
	1104,     0,     0,     0,  1107,     0,     0,  1115,  1116,     0,
	1118,   412,     0,   413,     0,  1123,     0,     0,     0,  1127,
	0,  1130,     0,  1132,     0,  1133,     0,  1134,  1135,   414,
	0,     0,  1136,     0,     0,     0,  1186,     0,     0,  1148,
	1149,     0,  1151,  1152,  1153,     0,     0,     0,     0,     0,
	1160,     2,     3,     4,     5,     6,     0,     7,     8,     9,
	10,    11,    12,     0,     0,     0,     0,    13,    14,     0,
	0,  1175,    16,    17,  1178,    18,   627,    19,     0,     0,
	1184,    20,    21,    22,    23,    24,    25,    26,    27,    28,
	29,    30,     0,    31,     0,    32,    33,    34,    35,    36,
	37,    38,    39,    40,  1093,     0,    41,    42,   278,   279,
	280,   281,   282,   283,     0,     0,     0,   825,   825,     0,
	528,   528,     0,   948,     0,     0,     0,     0,     0,     0,
	0,   953,   616,   616,     0,     0,    43,   958,     0,     0,
	616,     0,   528,     0,   627,     0,     0,     0,     0,     2,
	3,     4,     5,     6,     0,     7,     8,     9,    10,    11,
	12,     0,     0,     0,     0,    13,    14,     0,     0,     0,
	16,    17,     0,    18,     0,    19,     0,     0,     0,    20,
	21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
	0,    31,     0,    32,    33,    34,    35,    36,    37,    38,
	39,    40,   627,   627,    41,    42,     0,  1066,   627,   627,
	627,  1016,  1017,  1018,  1019,  1020,  1021,     0,    44,     0,
	0,     0,    45,  1080,     0,     0,     0,     0,     0,     0,
	0,     0,     0,  1022,    43,     0,     0,     0,  1023,     0,
	0,  1024,   898,   899,  1025,     0,  1091,   984,   985,   986,
	987,   988,   989,   990,   991,   992,   993,     0,     0,     0,
	0,     0,     0,     0,    46,     0,  1098,  1099,     0,   994,
	0,  1026,     0,  1105,  1106,   161,   162,   163,   164,   165,
	0,  1117,     0,  1027,  1120,     0,  1122,     0,     0,     0,
	0,   525,   227,   228,  1131,     0,   229,   230,   231,   232,
	233,   234,   235,   236,   627,   616,   627,     0,     0,     0,
	0,   995,     0,  1150,     0,     0,    44,     0,     0,   996,
	45,     0,     0,     0,     0,     0,   166,     0,     0,     0,
	0,     0,     0,   167,   168,   169,     0,     0,     0,     0,
	0,     0,     0,     0,  1177,     0,     0,     0,     0,  1183,
	0,     0,     0,   525,     0,   148,     0,   149,  1075,   150,
	0,   151,    46,   152,   477,   153,     0,   154,  1084,   155,
	0,   156,     0,   157,     0,   158,     0,   159,     0,   160,
	0,     0,     0,   173,     0,   174,     0,   175,     0,   176,
	0,   177,     0,   178,     0,   179,     0,   180,     0,   181,
	0,   182,     0,   183,     0,   184,     0,   185,     0,   186,
	0,   187,     0,   188,     0,   189,     0,   190,     0,   191,
	0,   192,     0,   193,     0,   194,     0,   195,     0,   196,
	0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
	0,     0,     0,    -6,     1,     0,     0,     0,     0,     0,
	2,     3,     4,     5,     6,     0,     7,     8,     9,    10,
	11,    12,     0,     0,     0,     0,    13,    14,    15,     0,
	0,    16,    17,     0,    18,     0,    19,     0,     0,     0,
	20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
	30,     0,    31,  1185,    32,    33,    34,    35,    36,    37,
	38,    39,    40,     0,     0,    41,    42,     2,     3,     4,
	5,     6,     0,     7,     8,     9,    10,    11,    12,     0,
	0,     0,     0,    13,    14,     0,     0,     0,    16,    17,
	0,    18,     0,    19,     0,    43,     0,    20,    21,    22,
	23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
	0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
	0,     0,    41,    42,     2,     3,     4,     5,     6,     0,
	7,     8,     9,    10,    11,    12,     0,     0,     0,     0,
	13,    14,     0,     0,     0,    16,    17,     0,    18,     0,
	19,     0,    43,     0,    20,    21,    22,    23,    24,    25,
	26,    27,    28,    29,    30,     0,    31,     0,    32,    33,
	34,    35,    36,    37,    38,    39,    40,    44,     0,    41,
	42,    45,   668,   669,   670,   671,   672,     0,   673,   674,
	675,   676,   677,     0,   678,   679,   680,   681,     0,   682,
	0,   683,   684,   685,     0,     0,     0,     0,     0,    43,
	0,     0,   686,   687,   688,   689,   690,     0,   691,   692,
	693,   694,   695,    46,   696,   697,   698,   699,     0,   700,
	0,   701,   702,   703,    44,     0,     0,     0,    45,   658,
	659,   660,   661,   662,   663,   664,     0,   665,   666,   667,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	46,     0,   590,     0,     0,     0,     0,     0,     0,     0,
	0,    44,     0,     0,     0,    45,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,    46,     0,   780,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	820,     0,     0,     0,     0,     0,     0,   821,     0,   822,
	0,   823,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,   889,     0,     0,     0,     0,
	0,   890,     0,   891,     0,   892,     0,   893,     0,   894,
	0,   895,     0,     0,     0,   905,     0,   906,     0,   907
};

static const short yycheck[] =
{
	44,    45,   161,   435,   275,   164,   165,   200,   221,    56,
	5,   289,   197,    14,    19,   163,     3,   295,    19,     3,
	168,   169,     3,     4,   895,     5,     3,     4,   897,   152,
	153,   225,     3,     4,    39,   356,     8,   358,   895,     3,
	364,   365,   246,     3,     4,     3,     4,    19,   206,   165,
	173,   174,     3,     4,   332,   333,   334,   205,   216,    14,
	219,   130,     0,   387,    19,   269,   224,    36,   261,    19,
	274,    19,   195,   123,   124,   223,  1011,   348,  1013,   237,
	3,     4,   353,     9,     3,     4,     3,     4,    38,     3,
	4,   900,    14,    19,   252,   373,   255,    19,   419,    19,
	984,    49,   260,   172,    30,   172,   264,    14,   379,    19,
	268,   226,    19,    16,     5,   273,    19,    16,   276,   278,
	19,   280,    16,   186,   328,    19,   284,    19,   287,    49,
	253,   452,  1016,   291,   165,   456,   329,   103,   296,   262,
	50,   345,    19,    19,   465,   293,    19,    39,   352,    64,
	428,    24,    92,   357,   224,  1024,     3,   985,   316,   203,
	204,   309,  1033,   321,   130,   131,   132,   152,   153,   327,
	85,   221,    55,     6,   378,   223,  1033,     6,  1047,   337,
	6,    96,    97,   342,   388,   389,   344,   996,   173,  1017,
	159,   349,    64,     6,   317,     6,   354,     6,   123,   124,
	323,   359,   361,   362,     6,   249,   172,     6,   366,    92,
	195,    90,   371,    92,    66,   220,    95,   375,  1027,   220,
	6,   902,   380,   382,    96,    97,   223,   385,     6,   224,
	443,   444,   390,   446,   393,   394,     6,   224,   222,  1048,
	398,    92,   222,   224,   437,   403,   290,   224,   220,   527,
	19,     6,   411,   224,   152,   153,   143,   415,   417,   418,
	223,    30,   420,    32,   224,   220,   224,   426,   253,   223,
	220,   222,   220,     6,   432,   173,   174,   262,   436,   166,
	167,   325,   440,   442,   477,   470,   445,   139,   140,   447,
	449,   174,   450,     6,   220,   178,   221,   195,   220,   222,
	220,     6,   460,   222,   463,   222,   247,   351,   222,   467,
	220,   469,   199,   220,    89,   473,     6,   220,   466,   363,
	6,   220,   263,   174,   472,   369,   220,   178,   220,   270,
	374,    66,   317,   377,     6,   222,   123,   124,   461,   383,
	384,   123,   124,   220,   220,   125,   126,   220,  1029,  1030,
	1031,  1032,   121,   128,     6,   253,     6,   244,   245,   246,
	247,    67,    68,    69,   262,   217,   218,   219,     6,   413,
	414,     3,     4,    64,    65,    66,   263,   114,   115,   423,
	75,    76,   269,   270,     6,   429,   430,   274,   163,   164,
	125,   126,   279,     6,   281,   282,   283,     6,    66,   286,
	6,   288,   289,    98,     6,    96,    97,   294,   295,   453,
	454,   455,   192,   845,   157,   177,   178,    66,   180,   317,
	464,    70,    71,    72,     6,   323,   157,   158,    96,    97,
	6,   579,   580,     6,   221,   172,   179,   180,     6,   221,
	183,   328,   185,     6,   331,   332,   333,   334,   335,   336,
	6,   220,   339,     6,   341,     6,   187,   188,   345,   783,
	6,   207,   208,   194,     6,   352,   161,   123,   124,   356,
	357,   358,     6,   168,   154,   155,   461,   364,   365,   225,
	129,   368,    99,   370,    89,   372,   373,   157,     6,   137,
	138,   378,   238,   239,   240,   241,   242,   243,   178,   179,
	387,   388,   389,   194,   149,   150,   550,     3,     4,   179,
	180,   827,   828,   183,    64,   185,  1166,  1167,   405,   406,
	407,   408,   409,   128,     6,   412,   847,   851,     6,    70,
	71,    72,   419,     6,   277,   422,     6,   424,   425,     6,
	427,   428,     6,   590,   431,   194,    96,    97,     6,   827,
	828,    92,   439,   170,   171,   172,   173,   162,   990,   164,
	992,   824,   825,   461,   169,   452,   579,   580,   223,   456,
	6,   849,   909,   910,    12,   462,   322,   223,   465,    99,
	223,    19,    20,   174,    22,   909,   910,   223,    26,    27,
	99,   915,   916,   917,   831,   832,    34,    35,   839,   840,
	346,    90,    64,    92,   154,   155,    95,   277,   169,  1041,
	48,   223,   355,     6,   222,   156,   136,   360,  1188,   223,
	223,  1012,    60,    61,    86,   818,    88,   136,   178,   179,
	211,   217,   226,   846,    96,    97,   401,   524,   381,   148,
	527,   528,   410,   193,   970,   134,   135,   248,   391,   169,
	170,   171,   172,   399,   253,   818,   271,  1089,   265,   976,
	169,   170,   171,   172,   173,   262,    66,   277,   983,   189,
	70,    71,    72,   292,   285,    75,   999,   151,   152,   153,
	189,   190,  1015,   297,   843,   355,   172,  1054,   317,   925,
	360,  1012,   166,  1033,   904,   323,   330,   102,   338,   104,
	213,   935,   850,   410,   355,   110,   111,   112,   113,   350,
	347,   381,   941,    99,   367,   928,   929,   122,   360,   376,
	1050,   391,   127,   381,   386,   125,   126,   391,   474,   616,
	404,   400,   619,   780,  1166,  1167,   421,   896,   416,  1053,
	627,   433,   438,  1014,   441,   903,   919,   448,  1061,   451,
	155,   461,   468,   470,   475,    -1,  1188,    -1,    -1,    -1,
	918,    -1,   921,   922,    -1,   923,    -1,    -1,   927,    -1,
	-1,    -1,   931,   932,    -1,   933,    -1,   936,   937,    -1,
	-1,   939,   220,   188,    -1,    -1,    -1,   831,   832,    -1,
	-1,    -1,    -1,    -1,   998,   181,   182,   183,   184,   185,
	-1,   141,   142,   143,   144,   145,   146,   147,   852,    -1,
	-1,   969,   971,   972,    -1,    -1,    -1,   975,   977,   978,
	979,    -1,    -1,    -1,   982,    -1,    -1,   986,   987,    -1,
	989,   171,    -1,   173,    -1,   994,    -1,    -1,    -1,   997,
	-1,  1000,    -1,  1002,    -1,  1004,    -1,  1006,  1007,   189,
	-1,    -1,  1010,    -1,    -1,    -1,  1060,    -1,    -1,  1018,
	1019,    -1,  1021,  1022,  1023,    -1,    -1,    -1,    -1,    -1,
	1028,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
	16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
	-1,  1049,    28,    29,  1052,    31,   783,    33,    -1,    -1,
	1058,    37,    38,    39,    40,    41,    42,    43,    44,    45,
	46,    47,    -1,    49,    -1,    51,    52,    53,    54,    55,
	56,    57,    58,    59,   968,    -1,    62,    63,    90,    91,
	92,    93,    94,    95,    -1,    -1,    -1,   824,   825,    -1,
	827,   828,    -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,   838,   839,   840,    -1,    -1,    92,   844,    -1,    -1,
	847,    -1,   849,    -1,   851,    -1,    -1,    -1,    -1,     7,
	8,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
	18,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
	28,    29,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,
	38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
	-1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
	58,    59,   909,   910,    62,    63,    -1,   914,   915,   916,
	917,   100,   101,   102,   103,   104,   105,    -1,   174,    -1,
	-1,    -1,   178,   930,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,   122,    92,    -1,    -1,    -1,   127,    -1,
	-1,   130,   131,   132,   133,    -1,   953,   100,   101,   102,
	103,   104,   105,   106,   107,   108,   109,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,   220,    -1,   973,   974,    -1,   122,
	-1,   160,    -1,   980,   981,   116,   117,   118,   119,   120,
	-1,   988,    -1,   172,   991,    -1,   993,    -1,    -1,    -1,
	-1,   998,    73,    74,  1001,    -1,    77,    78,    79,    80,
	81,    82,    83,    84,  1011,  1012,  1013,    -1,    -1,    -1,
	-1,   164,    -1,  1020,    -1,    -1,   174,    -1,    -1,   172,
	178,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,
	-1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,  1051,    -1,    -1,    -1,    -1,  1056,
	-1,    -1,    -1,  1060,    -1,    57,    -1,    59,   924,    61,
	-1,    63,   220,    65,   222,    67,    -1,    69,   934,    71,
	-1,    73,    -1,    75,    -1,    77,    -1,    79,    -1,    81,
	-1,    -1,    -1,    85,    -1,    87,    -1,    89,    -1,    91,
	-1,    93,    -1,    95,    -1,    97,    -1,    99,    -1,   101,
	-1,   103,    -1,   105,    -1,   107,    -1,   109,    -1,   111,
	-1,   113,    -1,   115,    -1,   117,    -1,   119,    -1,   121,
	-1,   123,    -1,   125,    -1,   127,    -1,   129,    -1,   131,
	-1,    -1,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
	7,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
	17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,
	-1,    28,    29,    -1,    31,    -1,    33,    -1,    -1,    -1,
	37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	47,    -1,    49,  1059,    51,    52,    53,    54,    55,    56,
	57,    58,    59,    -1,    -1,    62,    63,     7,     8,     9,
	10,    11,    -1,    13,    14,    15,    16,    17,    18,    -1,
	-1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    29,
	-1,    31,    -1,    33,    -1,    92,    -1,    37,    38,    39,
	40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
	-1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
	-1,    -1,    62,    63,     7,     8,     9,    10,    11,    -1,
	13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
	23,    24,    -1,    -1,    -1,    28,    29,    -1,    31,    -1,
	33,    -1,    92,    -1,    37,    38,    39,    40,    41,    42,
	43,    44,    45,    46,    47,    -1,    49,    -1,    51,    52,
	53,    54,    55,    56,    57,    58,    59,   174,    -1,    62,
	63,   178,   195,   196,   197,   198,   199,    -1,   201,   202,
	203,   204,   205,    -1,   207,   208,   209,   210,    -1,   212,
	-1,   214,   215,   216,    -1,    -1,    -1,    -1,    -1,    92,
	-1,    -1,   195,   196,   197,   198,   199,    -1,   201,   202,
	203,   204,   205,   220,   207,   208,   209,   210,    -1,   212,
	-1,   214,   215,   216,   174,    -1,    -1,    -1,   178,   195,
	196,   197,   198,   199,   200,   201,    -1,   203,   204,   205,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,   174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,   222,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	492,    -1,    -1,    -1,    -1,    -1,    -1,   499,    -1,   501,
	-1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,   717,    -1,    -1,    -1,    -1,
	-1,   723,    -1,   725,    -1,   727,    -1,   729,    -1,   731,
	-1,   733,    -1,    -1,    -1,   737,    -1,   739,    -1,   741
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
	0,     1,     7,     8,     9,    10,    11,    13,    14,    15,
	16,    17,    18,    23,    24,    25,    28,    29,    31,    33,
	37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
	47,    49,    51,    52,    53,    54,    55,    56,    57,    58,
	59,    62,    63,    92,   174,   178,   220,   228,   229,   230,
	231,   232,   234,   235,   236,   237,   238,   271,   272,   275,
	276,   280,   281,   294,   295,   298,   299,   309,   310,   313,
	314,   319,   320,   326,   327,   330,   331,   338,   339,   342,
	343,   359,   360,   364,   365,   368,   369,   390,   391,   396,
	397,   400,   401,   411,   412,   415,   416,   419,   420,   423,
	424,   432,   433,   436,   437,   444,   445,   448,   449,   452,
	453,   457,   458,   461,   462,   465,   466,   473,   474,   477,
	478,   482,   483,   492,   493,   500,   501,   504,   505,   508,
	509,   512,   513,   515,   516,   520,   521,   225,   263,     3,
	240,     3,     4,   242,   248,   248,     0,   229,   263,   263,
	263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
	263,   116,   117,   118,   119,   120,   167,   174,   175,   176,
	361,   362,   363,   263,   263,   263,   263,   263,   263,   263,
	263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
	263,   263,   263,   263,   263,   263,   263,   263,   263,   242,
	64,    65,    66,    96,    97,   194,   265,   266,   267,   268,
	269,   270,   305,    67,    68,    69,   273,   274,    66,    70,
	71,    72,   129,   194,   277,   278,   279,    73,    74,    77,
	78,    79,    80,    81,    82,    83,    84,   282,   283,   284,
	285,   286,   287,   288,   289,   290,   291,   292,   293,    85,
	268,   269,   296,   297,   305,    86,    88,   268,   269,   305,
	306,   307,   308,   172,   311,   312,   123,   124,   315,   316,
	317,   318,   165,   325,   316,   317,   328,   329,    90,    91,
	92,    93,    94,    95,   336,   337,    99,   170,   171,   172,
	173,   340,   341,   114,   115,   172,   357,   358,   240,     5,
	241,   240,   240,   242,   242,   241,   241,   226,   264,   222,
	241,   256,   361,   268,   269,   305,   366,   367,    66,   268,
	269,   387,   388,   389,   177,   178,   180,   392,   393,   394,
	395,    99,   181,   182,   183,   184,   185,   398,   399,    75,
	76,    98,   161,   168,   407,   408,   409,   410,   186,   413,
	414,   221,   316,   317,   417,   418,   221,   316,   317,   421,
	422,    90,    92,    95,   134,   135,   430,   431,    99,   136,
	169,   170,   171,   172,   189,   434,   435,   221,   316,   317,
	442,   443,    92,   174,   178,   446,   447,   221,   316,   317,
	450,   451,    66,   139,   140,   217,   218,   219,   454,   455,
	456,   137,   138,   459,   460,   141,   142,   143,   144,   145,
	146,   147,   171,   173,   189,   463,   464,    90,    92,    95,
	471,   472,    99,   136,   148,   169,   170,   171,   172,   173,
	189,   190,   475,   476,   149,   150,   479,   480,   481,   165,
	490,   491,    70,    71,    72,    92,   156,   498,   499,    92,
	502,   503,   154,   155,   178,   179,   193,   268,   269,   305,
	506,   507,   157,   158,   187,   188,   194,   510,   511,   514,
	515,    36,   159,   517,   518,   519,   242,   222,   238,   248,
	248,   241,   264,   256,   256,   265,    19,   220,   401,    19,
	50,   220,   496,   497,    19,    30,    32,   121,   220,   373,
	374,   405,   406,   428,   429,   264,   273,   240,     3,     4,
	243,   243,   242,   241,   264,   256,   277,   264,   256,   256,
	256,   256,   256,   256,   222,   242,   254,   222,   242,   244,
	250,   254,   250,   282,   248,   264,   296,   240,    19,   220,
	264,   238,   306,   250,   264,   311,   264,   254,   250,   315,
	222,   248,   260,   264,   254,   260,   264,   328,   240,   242,
	240,   242,   242,   242,   264,   336,   242,   240,   242,   244,
	248,   264,   340,   241,   242,   244,   264,   357,   224,   224,
	241,   255,   264,   366,   264,   256,   387,   248,   264,   254,
	222,   238,   392,   242,   244,   244,   244,   242,   242,   264,
	398,   242,   242,   240,   264,   254,   256,   407,   260,   264,
	413,   248,   254,   260,   264,   417,   242,   245,   254,   222,
	245,   262,   264,   421,   240,   240,   248,   242,   247,   247,
	264,   430,   242,   248,   242,   240,   242,   244,   248,   264,
	434,   248,   254,   260,   264,   442,   240,   248,   248,   264,
	446,   247,   254,   254,   264,   450,   240,   240,   195,   196,
	197,   198,   199,   200,   201,   203,   204,   205,   195,   196,
	197,   198,   199,   201,   202,   203,   204,   205,   207,   208,
	209,   210,   212,   214,   215,   216,   195,   196,   197,   198,
	199,   201,   202,   203,   204,   205,   207,   208,   209,   210,
	212,   214,   215,   216,   264,   256,   454,    19,   220,   276,
	12,    19,    20,    22,    26,    27,    34,    35,    48,    60,
	61,   220,   233,   302,   303,   323,   324,   334,   335,   347,
	348,   355,   356,   381,   382,   385,   386,   440,   441,   469,
	470,   488,   489,   264,   459,   242,   242,   242,   242,   242,
	19,   220,   281,   406,   240,   242,   248,   248,   264,   463,
	240,   240,   245,   264,   471,   242,   248,   242,   242,   240,
	242,   244,   248,   248,   242,   264,   475,     3,   239,   264,
	222,   238,   479,   222,   247,   258,   264,   490,   240,   243,
	243,   240,   243,   264,   498,   240,   264,   502,   245,   248,
	248,   248,   245,   264,   506,   242,   240,   248,   245,   241,
	264,   510,   264,   514,   241,   264,   256,   517,   238,   304,
	263,   263,   263,   263,   224,   242,   253,   224,   244,   249,
	242,   224,   248,   259,   255,   255,   223,   229,   242,   224,
	245,   261,   242,     6,     6,     6,     6,     6,     6,     6,
	6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
	6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
	6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
	6,     6,     6,     6,     6,     6,     6,     6,     6,   263,
	263,   263,   263,   263,   263,   263,   103,   130,   131,   132,
	172,   376,   377,   383,   384,   263,   263,   263,   229,   224,
	247,   257,   304,   223,   154,   155,   178,   179,   494,   495,
	66,   125,   126,   370,   371,   372,    66,    70,    71,    72,
	75,   125,   126,   402,   403,   404,   125,   126,   192,   425,
	426,   427,   253,   253,   223,   249,   249,   223,   242,   259,
	259,   223,   223,   242,   261,   261,   223,   240,   242,   239,
	243,   245,    19,   220,   244,   241,   247,   248,   174,   300,
	301,    89,   128,   163,   164,   321,   322,    89,   128,   162,
	164,   169,   332,   333,   100,   101,   102,   103,   104,   105,
	106,   107,   108,   109,   122,   164,   172,   344,   345,   346,
	102,   104,   110,   111,   112,   113,   122,   127,   155,   188,
	349,   350,   351,   352,   353,   354,   100,   101,   102,   103,
	104,   105,   122,   127,   130,   133,   160,   172,   375,   376,
	377,   378,   379,   380,   240,    19,   220,   327,    19,   220,
	314,   222,   239,   252,   252,   264,   383,   130,   172,   438,
	439,   169,   467,   468,   151,   152,   153,   166,   484,   485,
	486,   487,   223,   257,   257,   223,   242,   247,   247,   247,
	264,   494,   240,   240,   264,   256,   370,   240,   243,   243,
	242,   240,   240,   264,   256,   402,   240,   240,   264,   222,
	425,   242,     6,   248,   264,   300,   240,   240,   242,   242,
	264,   321,   240,   240,   240,   242,   242,   264,   332,    19,
	220,   416,    19,   220,   493,   240,   240,   242,   240,   239,
	242,   239,   242,   240,    19,   220,   314,   264,   254,   344,
	240,   242,   240,   240,   240,   240,   264,   258,   262,   258,
	260,   349,    19,   220,   416,    19,   220,   493,   240,   240,
	242,   240,   240,   240,    19,   220,   327,    19,   220,   314,
	264,   252,   252,   252,   252,   375,   224,   239,   251,    19,
	220,   327,    19,   220,   314,   264,   438,   242,   264,   467,
	19,   220,   365,   242,   264,   256,   254,   484,   239,   246,
	251,   251,   223,   246,   223
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print(short *bottom, short *top)
#else
static void
yy_stack_print(bottom, top)
short *bottom;
short *top;
#endif
{
	YYFPRINTF(stderr, "Stack now");
	for(/* Nothing. */; bottom <= top; ++bottom)
		YYFPRINTF(stderr, " %d", *bottom);
	YYFPRINTF(stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print(int yyrule)
#else
static void
yy_reduce_print(yyrule)
int yyrule;
#endif
{
	int yyi;
	unsigned int yylno = yyrline[yyrule];
	YYFPRINTF(stderr, "Reducing stack by rule %d (line %u), ",
	          yyrule - 1, yylno);
	/* Print the symbols being reduced, and their result.  */
	for(yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
		YYFPRINTF(stderr, "%s ", yytname [yyrhs[yyi]]);
	YYFPRINTF(stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug = 1;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen(const char *yystr)
#   else
yystrlen(yystr)
const char *yystr;
#   endif
{
	register const char *yys = yystr;

	while(*yys++ != '\0')
		continue;

	return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy(char *yydest, const char *yysrc)
#   else
yystpcpy(yydest, yysrc)
char *yydest;
const char *yysrc;
#   endif
{
	register char *yyd = yydest;
	register const char *yys = yysrc;

	while((*yyd++ = *yys++) != '\0')
		continue;

	return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint(FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint(yyoutput, yytype, yyvaluep)
FILE *yyoutput;
int yytype;
YYSTYPE *yyvaluep;
#endif
{
	/* Pacify ``unused variable'' warnings.  */
	(void) yyvaluep;
	
	if(yytype < YYNTOKENS)
	{
		YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
		YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
# endif
	}
	else
		YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);
		
	switch(yytype)
	{
	default:
		break;
	}
	YYFPRINTF(yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct(int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct(yytype, yyvaluep)
int yytype;
YYSTYPE *yyvaluep;
#endif
{
	/* Pacify ``unused variable'' warnings.  */
	(void) yyvaluep;
	
	switch(yytype)
	{
	
	default:
		break;
	}
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse(void *YYPARSE_PARAM);
# else
int yyparse();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse(void);
#else
int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse(void *YYPARSE_PARAM)
# else
int yyparse(YYPARSE_PARAM)
void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse(void)
#else
int
yyparse()

#endif
#endif
{

	register int yystate;
	register int yyn;
	int yyresult;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus;
	/* Lookahead token as an internal (translated) token number.  */
	int yytoken = 0;
	
	/* Three stacks and their tools:
	   `yyss': related to states,
	   `yyvs': related to semantic values,
	   `yyls': related to locations.
	
	   Refer to the stacks thru separate pointers, to allow yyoverflow
	   to reallocate them elsewhere.  */
	
	/* The state stack.  */
	short	yyssa[YYINITDEPTH];
	short *yyss = yyssa;
	register short *yyssp;
	
	/* The semantic value stack.  */
	YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE *yyvs = yyvsa;
	register YYSTYPE *yyvsp;
	
	
	
#define YYPOPSTACK   (yyvsp--, yyssp--)
	
	YYSIZE_T yystacksize = YYINITDEPTH;
	
	/* The variables used to return semantic value and location from the
	   action routines.  */
	YYSTYPE yyval;
	
	
	/* When reducing, the number of symbols on the RHS of the reduced
	   rule.  */
	int yylen;
	
	YYDPRINTF((stderr, "Starting parse\n"));
	
	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY;		/* Cause a token to be read.  */
	
	/* Initialize stack pointers.
	   Waste one element of value and location stack
	   so that they stay on the same level as the state stack.
	   The wasted elements are never initialized.  */
	
	yyssp = yyss;
	yyvsp = yyvs;
	
	goto yysetstate;
	
	/*------------------------------------------------------------.
	| yynewstate -- Push a new state, which is found in yystate.  |
	`------------------------------------------------------------*/
yynewstate:
	/* In all cases, when you get here, the value and location stacks
	   have just been pushed. so pushing a state here evens the stacks.
	   */
	yyssp++;
	
yysetstate:
	*yyssp = yystate;
	
	if(yyss + yystacksize - 1 <= yyssp)
	{
		/* Get the current used size of the three stacks, in elements.  */
		YYSIZE_T yysize = yyssp - yyss + 1;
		
#ifdef yyoverflow
		{
			/* Give user a chance to reallocate the stack. Use copies of
			   these so that the &'s don't force the real ones into
			   memory.  */
			YYSTYPE *yyvs1 = yyvs;
			short *yyss1 = yyss;
			
			
			/* Each stack pointer address is followed by the size of the
			   data in use in that stack, in bytes.  This used to be a
			   conditional around just the two extra args, but that might
			   be undefined if yyoverflow is a macro.  */
			yyoverflow("parser stack overflow",
			           &yyss1, yysize * sizeof(*yyssp),
			           &yyvs1, yysize * sizeof(*yyvsp),
			           
			           &yystacksize);
			           
			yyss = yyss1;
			yyvs = yyvs1;
		}
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
		goto yyoverflowlab;
# else
		/* Extend the stack our own way.  */
		if(YYMAXDEPTH <= yystacksize)
			goto yyoverflowlab;
		yystacksize *= 2;
		if(YYMAXDEPTH < yystacksize)
			yystacksize = YYMAXDEPTH;
		
		{
			short *yyss1 = yyss;
			union yyalloc *yyptr =
					    (union yyalloc *) YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
			if(! yyptr)
				goto yyoverflowlab;
			YYSTACK_RELOCATE(yyss);
			YYSTACK_RELOCATE(yyvs);
		
#  undef YYSTACK_RELOCATE
			if(yyss1 != yyssa)
				YYSTACK_FREE(yyss1);
		}
# endif
#endif /* no yyoverflow */
		
		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;
		
		
		YYDPRINTF((stderr, "Stack size increased to %lu\n",
		           (unsigned long int) yystacksize));
		           
		if(yyss + yystacksize - 1 <= yyssp)
			YYABORT;
	}
	
	YYDPRINTF((stderr, "Entering state %d\n", yystate));
	
	goto yybackup;
	
	/*-----------.
	| yybackup.  |
	`-----------*/
yybackup:

	/* Do appropriate processing given the current state.  */
	/* Read a lookahead token if we need one and don't already have one.  */
	/* yyresume: */
	
	/* First try to decide what to do without reference to lookahead token.  */
	
	yyn = yypact[yystate];
	if(yyn == YYPACT_NINF)
		goto yydefault;
		
	/* Not known => get a lookahead token if don't already have one.  */
	
	/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
	if(yychar == YYEMPTY)
	{
		YYDPRINTF((stderr, "Reading a token: "));
		yychar = YYLEX;
	}
	
	if(yychar <= YYEOF)
	{
		yychar = yytoken = YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	}
	else
	{
		yytoken = YYTRANSLATE(yychar);
		YYDSYMPRINTF("Next token is", yytoken, &yylval, &yylloc);
	}
	
	/* If the proper action on seeing token YYTOKEN is to reduce or to
	   detect an error, take that action.  */
	yyn += yytoken;
	if(yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
		goto yydefault;
	yyn = yytable[yyn];
	if(yyn <= 0)
	{
		if(yyn == 0 || yyn == YYTABLE_NINF)
			goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}
	
	if(yyn == YYFINAL)
		YYACCEPT;
		
	/* Shift the lookahead token.  */
	//YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
	
	/* Discard the token being shifted unless it is eof.  */
	if(yychar != YYEOF)
		yychar = YYEMPTY;
		
	*++yyvsp = yylval;
	
	
	/* Count tokens shifted since error; after three, turn off error
	   status.  */
	if(yyerrstatus)
		yyerrstatus--;
		
	yystate = yyn;
	goto yynewstate;
	
	
	/*-----------------------------------------------------------.
	| yydefault -- do the default action for the current state.  |
	`-----------------------------------------------------------*/
yydefault:
	yyn = yydefact[yystate];
	if(yyn == 0)
		goto yyerrlab;
	goto yyreduce;
	
	
	/*-----------------------------.
	| yyreduce -- Do a reduction.  |
	`-----------------------------*/
yyreduce:
	/* yyn is the number of a rule to reduce with.  */
	yylen = yyr2[yyn];
	
	/* If YYLEN is nonzero, implement the default value of the action:
	   `$$ = $1'.
	
	   Otherwise, the following line sets YYVAL to garbage.
	   This behavior is undocumented and Bison
	   users should not rely upon it.  Assigning to YYVAL
	   unconditionally makes the parser a bit smaller, and it avoids a
	   GCC warning that YYVAL may be used uninitialized.  */
	yyval = yyvsp[1-yylen];
	
	
	YY_REDUCE_PRINT(yyn);
	switch(yyn)
	{
	case 3:
//#line 109 "VRML97.y"
	{
		YYABORT;
	}
	break;
	
	case 4:
//#line 110 "VRML97.y"
	{
		YYABORT;
	}
	break;
	
	case 65:
//#line 205 "VRML97.y"
	{
		AddSFInt32(yyvsp[0].ival);
	}
	break;
	
	case 67:
//#line 216 "VRML97.y"
	{
		AddSFString(yyvsp[0].sval);
	}
	break;
	
	case 68:
//#line 223 "VRML97.y"
	{
		AddSFFloat(yyvsp[0].fval);
	}
	break;
	
	case 69:
//#line 227 "VRML97.y"
	{
		yyval.fval = (float)yyvsp[0].ival;
		AddSFFloat((float)yyvsp[0].ival);
	}
	break;
	
	case 71:
//#line 235 "VRML97.y"
	{
		yyval.fval = (float)yyvsp[0].ival;
	}
	break;
	
	case 72:
//#line 240 "VRML97.y"
	{
		gColor[0] = yyvsp[-2].fval;
		gColor[1] = yyvsp[-1].fval;
		gColor[2] = yyvsp[0].fval;
		AddSFColor(gColor);
	}
	break;
	
	case 73:
//#line 250 "VRML97.y"
	{
		gRotation[0] = yyvsp[-3].fval;
		gRotation[1] = yyvsp[-2].fval;
		gRotation[2] = yyvsp[-1].fval;
		gRotation[3] = yyvsp[0].fval;
		AddSFRotation(gRotation);
	}
	break;
	
	case 74:
//#line 260 "VRML97.y"
	{}
	break;
	
	case 76:
//#line 280 "VRML97.y"
	{
		gVec2f[0] = yyvsp[-1].fval;
		gVec2f[1] = yyvsp[0].fval;
		AddSFVec2f(gVec2f);
	}
	break;
	
	case 77:
//#line 289 "VRML97.y"
	{
		gVec3f[0] = yyvsp[-2].fval;
		gVec3f[1] = yyvsp[-1].fval;
		gVec3f[2] = yyvsp[0].fval;
		AddSFVec3f(gVec3f);
	}
	break;
	
	case 84:
//#line 310 "VRML97.y"
	{}
	break;
	
	case 85:
//#line 311 "VRML97.y"
	{}
	break;
	
	case 86:
//#line 312 "VRML97.y"
	{}
	break;
	
	case 88:
//#line 317 "VRML97.y"
	{}
	break;
	
	case 89:
//#line 318 "VRML97.y"
	{}
	break;
	
	case 90:
//#line 323 "VRML97.y"
	{}
	break;
	
	case 91:
//#line 324 "VRML97.y"
	{}
	break;
	
	case 92:
//#line 325 "VRML97.y"
	{}
	break;
	
	case 94:
//#line 330 "VRML97.y"
	{}
	break;
	
	case 95:
//#line 331 "VRML97.y"
	{}
	break;
	
	case 96:
//#line 335 "VRML97.y"
	{}
	break;
	
	case 97:
//#line 336 "VRML97.y"
	{}
	break;
	
	case 98:
//#line 337 "VRML97.y"
	{}
	break;
	
	case 100:
//#line 342 "VRML97.y"
	{}
	break;
	
	case 101:
//#line 343 "VRML97.y"
	{}
	break;
	
	case 125:
//#line 404 "VRML97.y"
	{
		ParserPushNode(VRML97_ANCHOR_PARAMETER, ParserGetCurrentNode());
	}
	break;
	
	case 126:
//#line 411 "VRML97.y"
	{
		ParserPushNode(VRML97_ANCHOR_URL, ParserGetCurrentNode());
	}
	break;
	
	case 127:
//#line 418 "VRML97.y"
	{
		((AnchorNode *)ParserGetCurrentNode())->setBoundingBoxCenter(gVec3f);
	}
	break;
	
	case 128:
//#line 425 "VRML97.y"
	{
		((AnchorNode *)ParserGetCurrentNode())->setBoundingBoxSize(gVec3f);
	}
	break;
	
	case 130:
//#line 433 "VRML97.y"
	{
		((AnchorNode *)ParserGetCurrentNode())->setDescription(yyvsp[0].sval);
	}
	break;
	
	case 131:
//#line 438 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 132:
//#line 442 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 135:
//#line 451 "VRML97.y"
	{
		AnchorNode	*anchor = new AnchorNode();
		anchor->setName(GetDEFName());
		ParserAddNode(anchor);
		ParserPushNode(VRML97_ANCHOR, anchor);
	}
	break;
	
	case 136:
//#line 461 "VRML97.y"
	{
		AnchorNode *anchor = (AnchorNode *)ParserGetCurrentNode();
		anchor->initialize();
		ParserPopNode();
	}
	break;
	
	case 150:
//#line 495 "VRML97.y"
	{
		AppearanceNode	*appearance = new AppearanceNode();
		appearance->setName(GetDEFName());
		ParserAddNode(appearance);
		ParserPushNode(VRML97_APPEARANCE, appearance);
	}
	break;
	
	case 151:
//#line 505 "VRML97.y"
	{
		AppearanceNode	*appearance = (AppearanceNode *)ParserGetCurrentNode();
		appearance->initialize();
		ParserPopNode();
	}
	break;
	
	case 154:
//#line 525 "VRML97.y"
	{
		ParserPushNode(VRML97_AUDIOCLIP_URL, ParserGetCurrentNode());
	}
	break;
	
	case 155:
//#line 532 "VRML97.y"
	{
		((AudioClipNode *)ParserGetCurrentNode())->setDescription(yyvsp[0].sval);
	}
	break;
	
	case 156:
//#line 536 "VRML97.y"
	{
		((AudioClipNode *)ParserGetCurrentNode())->setLoop(yyvsp[0].ival);
	}
	break;
	
	case 157:
//#line 540 "VRML97.y"
	{
		((AudioClipNode *)ParserGetCurrentNode())->setPitch(yyvsp[0].fval);
	}
	break;
	
	case 158:
//#line 544 "VRML97.y"
	{
		((AudioClipNode *)ParserGetCurrentNode())->setStartTime(yyvsp[0].fval);
	}
	break;
	
	case 159:
//#line 548 "VRML97.y"
	{
		((AudioClipNode *)ParserGetCurrentNode())->setStopTime(yyvsp[0].fval);
	}
	break;
	
	case 160:
//#line 552 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 161:
//#line 559 "VRML97.y"
	{
		AudioClipNode	*audioClip = new AudioClipNode();
		audioClip->setName(GetDEFName());
		ParserAddNode(audioClip);
		ParserPushNode(VRML97_AUDIOCLIP, audioClip);
	}
	break;
	
	case 162:
//#line 569 "VRML97.y"
	{
		AudioClipNode *audioClip = (AudioClipNode *)ParserGetCurrentNode();
		audioClip->initialize();
		ParserPopNode();
	}
	break;
	
	case 165:
//#line 589 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_BACKURL, ParserGetCurrentNode());
	}
	break;
	
	case 166:
//#line 596 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_BOTTOMURL, ParserGetCurrentNode());
	}
	break;
	
	case 167:
//#line 603 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_FRONTURL, ParserGetCurrentNode());
	}
	break;
	
	case 168:
//#line 610 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_LEFTURL, ParserGetCurrentNode());
	}
	break;
	
	case 169:
//#line 617 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_RIGHTURL, ParserGetCurrentNode());
	}
	break;
	
	case 170:
//#line 624 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_TOPURL, ParserGetCurrentNode());
	}
	break;
	
	case 171:
//#line 631 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_GROUNDANGLE, ParserGetCurrentNode());
	}
	break;
	
	case 172:
//#line 638 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_GROUNDCOLOR, ParserGetCurrentNode());
	}
	break;
	
	case 173:
//#line 645 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_SKYANGLE, ParserGetCurrentNode());
	}
	break;
	
	case 174:
//#line 652 "VRML97.y"
	{
		ParserPushNode(VRML97_BACKGROUND_SKYCOLOR, ParserGetCurrentNode());
	}
	break;
	
	case 175:
//#line 659 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 176:
//#line 663 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 177:
//#line 667 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 178:
//#line 671 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 179:
//#line 675 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 180:
//#line 679 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 181:
//#line 683 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 182:
//#line 687 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 183:
//#line 691 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 184:
//#line 695 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 185:
//#line 702 "VRML97.y"
	{
		BackgroundNode *bg = new BackgroundNode();
		bg->setName(GetDEFName());
		ParserAddNode(bg);
		ParserPushNode(VRML97_BACKGROUND, bg);
	}
	break;
	
	case 186:
//#line 712 "VRML97.y"
	{
		BackgroundNode *bg = (BackgroundNode *)ParserGetCurrentNode();
		bg->initialize();
		ParserPopNode();
	}
	break;
	
	case 190:
//#line 733 "VRML97.y"
	{
		((BillboardNode *)ParserGetCurrentNode())->setAxisOfRotation(gVec3f);
	}
	break;
	
	case 193:
//#line 742 "VRML97.y"
	{
		BillboardNode *billboard = new BillboardNode();
		billboard->setName(GetDEFName());
		ParserAddNode(billboard);
		ParserPushNode(VRML97_BILLBOARD, billboard);
	}
	break;
	
	case 194:
//#line 752 "VRML97.y"
	{
		BillboardNode *billboard = (BillboardNode *)ParserGetCurrentNode();
		billboard->initialize();
		ParserPopNode();
	}
	break;
	
	case 197:
//#line 772 "VRML97.y"
	{
		((BoxNode *)ParserGetCurrentNode())->setSize(gVec3f);
	}
	break;
	
	case 198:
//#line 779 "VRML97.y"
	{
		BoxNode *box = new BoxNode();
		box->setName(GetDEFName());
		ParserAddNode(box);
		ParserPushNode(VRML97_BOX, box);
	}
	break;
	
	case 199:
//#line 789 "VRML97.y"
	{
		BoxNode *box = (BoxNode *)ParserGetCurrentNode();
		box->initialize();
		ParserPopNode();
	}
	break;
	
	case 206:
//#line 825 "VRML97.y"
	{
		ParserPushNode(VRML97_COLLISION_PROXY, ParserGetCurrentNode());
	}
	break;
	
	case 208:
//#line 833 "VRML97.y"
	{
		((CollisionNode *)ParserGetCurrentNode())->setCollide(yyvsp[0].ival);
	}
	break;
	
	case 213:
//#line 841 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 214:
//#line 848 "VRML97.y"
	{
		CollisionNode *collision = new CollisionNode();
		collision->setName(GetDEFName());
		ParserAddNode(collision);
		ParserPushNode(VRML97_BOX, collision);
	}
	break;
	
	case 215:
//#line 858 "VRML97.y"
	{
		CollisionNode *collision = (CollisionNode *)ParserGetCurrentNode();
		collision->initialize();
		ParserPopNode();
	}
	break;
	
	case 219:
//#line 882 "VRML97.y"
	{
		ColorNode *color = new ColorNode();
		color->setName(GetDEFName());
		ParserAddNode(color);
		ParserPushNode(VRML97_COLOR, color);
	}
	break;
	
	case 220:
//#line 892 "VRML97.y"
	{
		ColorNode *color = (ColorNode *)ParserGetCurrentNode();
		color->initialize();
		ParserPopNode();
	}
	break;
	
	case 223:
//#line 912 "VRML97.y"
	{
		ParserPushNode(VRML97_INTERPOLATOR_KEY, ParserGetCurrentNode());
	}
	break;
	
	case 224:
//#line 919 "VRML97.y"
	{
		ParserPushNode(VRML97_INTERPOLATOR_KEYVALUE, ParserGetCurrentNode());
	}
	break;
	
	case 225:
//#line 926 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 226:
//#line 930 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 227:
//#line 937 "VRML97.y"
	{
		ColorInterpolatorNode *colInterp = new ColorInterpolatorNode();
		colInterp->setName(GetDEFName());
		ParserAddNode(colInterp);
		ParserPushNode(VRML97_COLORINTERPOLATOR, colInterp);
	}
	break;
	
	case 228:
//#line 947 "VRML97.y"
	{
		ColorInterpolatorNode *colInterp = (ColorInterpolatorNode *)ParserGetCurrentNode();
		colInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 231:
//#line 967 "VRML97.y"
	{
		((ConeNode *)ParserGetCurrentNode())->setSide(yyvsp[0].ival);
	}
	break;
	
	case 232:
//#line 971 "VRML97.y"
	{
		((ConeNode *)ParserGetCurrentNode())->setBottom(yyvsp[0].ival);
	}
	break;
	
	case 233:
//#line 975 "VRML97.y"
	{
		((ConeNode *)ParserGetCurrentNode())->setBottomRadius(yyvsp[0].fval);
	}
	break;
	
	case 234:
//#line 979 "VRML97.y"
	{
		((ConeNode *)ParserGetCurrentNode())->setHeight(yyvsp[0].fval);
	}
	break;
	
	case 235:
//#line 986 "VRML97.y"
	{
		ConeNode *cone = new ConeNode();
		cone->setName(GetDEFName());
		ParserAddNode(cone);
		ParserPushNode(VRML97_CONE, cone);
	}
	break;
	
	case 236:
//#line 996 "VRML97.y"
	{
		ConeNode *cone = (ConeNode *)ParserGetCurrentNode();
		cone->initialize();
		ParserPopNode();
	}
	break;
	
	case 239:
//#line 1016 "VRML97.y"
	{
		CoordinateNode *coord = new CoordinateNode();
		coord->setName(GetDEFName());
		ParserAddNode(coord);
		ParserPushNode(VRML97_COORDINATE, coord);
	}
	break;
	
	case 240:
//#line 1026 "VRML97.y"
	{
		CoordinateNode *coord = (CoordinateNode *)ParserGetCurrentNode();
		coord->initialize();
		ParserPopNode();
	}
	break;
	
	case 243:
//#line 1046 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 244:
//#line 1050 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 245:
//#line 1057 "VRML97.y"
	{
		CoordinateInterpolatorNode *coordInterp = new CoordinateInterpolatorNode();
		coordInterp->setName(GetDEFName());
		ParserAddNode(coordInterp);
		ParserPushNode(VRML97_COORDINATEINTERPOLATOR, coordInterp);
	}
	break;
	
	case 246:
//#line 1067 "VRML97.y"
	{
		CoordinateInterpolatorNode *coordInterp = (CoordinateInterpolatorNode *)ParserGetCurrentNode();
		coordInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 249:
//#line 1087 "VRML97.y"
	{
		((CylinderNode *)ParserGetCurrentNode())->setSide(yyvsp[0].ival);
	}
	break;
	
	case 250:
//#line 1091 "VRML97.y"
	{
		((CylinderNode *)ParserGetCurrentNode())->setBottom(yyvsp[0].ival);
	}
	break;
	
	case 251:
//#line 1095 "VRML97.y"
	{
		((CylinderNode *)ParserGetCurrentNode())->setTop(yyvsp[0].ival);
	}
	break;
	
	case 252:
//#line 1099 "VRML97.y"
	{
		((CylinderNode *)ParserGetCurrentNode())->setRadius(yyvsp[0].fval);
	}
	break;
	
	case 253:
//#line 1103 "VRML97.y"
	{
		((CylinderNode *)ParserGetCurrentNode())->setHeight(yyvsp[0].fval);
	}
	break;
	
	case 254:
//#line 1110 "VRML97.y"
	{
		CylinderNode *cylinder = new CylinderNode();
		cylinder->setName(GetDEFName());
		ParserAddNode(cylinder);
		ParserPushNode(VRML97_CYLINDER, cylinder);
	}
	break;
	
	case 255:
//#line 1120 "VRML97.y"
	{
		CylinderNode *cylinder = (CylinderNode *)ParserGetCurrentNode();
		cylinder->initialize();
		ParserPopNode();
	}
	break;
	
	case 258:
//#line 1140 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setAutoOffset(yyvsp[0].ival);
	}
	break;
	
	case 259:
//#line 1144 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setDiskAngle(yyvsp[0].fval);
	}
	break;
	
	case 260:
//#line 1148 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 261:
//#line 1152 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setMaxAngle(yyvsp[0].fval);
	}
	break;
	
	case 262:
//#line 1156 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setMinAngle(yyvsp[0].fval);
	}
	break;
	
	case 263:
//#line 1160 "VRML97.y"
	{
		((CylinderSensorNode *)ParserGetCurrentNode())->setOffset(yyvsp[0].fval);
	}
	break;
	
	case 264:
//#line 1168 "VRML97.y"
	{
		CylinderSensorNode *cysensor = new CylinderSensorNode();
		cysensor->setName(GetDEFName());
		ParserAddNode(cysensor);
		ParserPushNode(VRML97_CYLINDERSENSOR, cysensor);
	}
	break;
	
	case 265:
//#line 1178 "VRML97.y"
	{
		CylinderSensorNode *cysensor = (CylinderSensorNode *)ParserGetCurrentNode();
		cysensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 268:
//#line 1198 "VRML97.y"
	{
		((DirectionalLightNode *)ParserGetCurrentNode())->setOn(yyvsp[0].ival);
	}
	break;
	
	case 269:
//#line 1202 "VRML97.y"
	{
		((DirectionalLightNode *)ParserGetCurrentNode())->setIntensity(yyvsp[0].fval);
	}
	break;
	
	case 270:
//#line 1206 "VRML97.y"
	{
		((DirectionalLightNode *)ParserGetCurrentNode())->setColor(gColor);
	}
	break;
	
	case 271:
//#line 1210 "VRML97.y"
	{
		((DirectionalLightNode *)ParserGetCurrentNode())->setDirection(gVec3f);
	}
	break;
	
	case 272:
//#line 1214 "VRML97.y"
	{
		((DirectionalLightNode *)ParserGetCurrentNode())->setAmbientIntensity(yyvsp[0].fval);
	}
	break;
	
	case 273:
//#line 1221 "VRML97.y"
	{
		DirectionalLightNode *dirLight = new DirectionalLightNode();
		dirLight->setName(GetDEFName());
		ParserAddNode(dirLight);
		ParserPushNode(VRML97_DIRECTIONALLIGHT, dirLight);
	}
	break;
	
	case 274:
//#line 1231 "VRML97.y"
	{
		DirectionalLightNode *dirLight = (DirectionalLightNode *)ParserGetCurrentNode();
		dirLight->initialize();
		ParserPopNode();
	}
	break;
	
	case 277:
//#line 1251 "VRML97.y"
	{
		ParserPushNode(VRML97_ELEVATIONGRID_HEIGHT, ParserGetCurrentNode());
	}
	break;
	
	case 287:
//#line 1268 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 288:
//#line 1272 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setCCW(yyvsp[0].ival);
	}
	break;
	
	case 289:
//#line 1276 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setCreaseAngle(yyvsp[0].fval);
	}
	break;
	
	case 290:
//#line 1280 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setSolid(yyvsp[0].ival);
	}
	break;
	
	case 291:
//#line 1284 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setColorPerVertex(yyvsp[0].ival);
	}
	break;
	
	case 292:
//#line 1288 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setNormalPerVertex(yyvsp[0].ival);
	}
	break;
	
	case 293:
//#line 1292 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setXDimension(yyvsp[0].ival);
	}
	break;
	
	case 294:
//#line 1296 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setXSpacing(yyvsp[0].fval);
	}
	break;
	
	case 295:
//#line 1300 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setZDimension(yyvsp[0].ival);
	}
	break;
	
	case 296:
//#line 1304 "VRML97.y"
	{
		((ElevationGridNode *)ParserGetCurrentNode())->setZSpacing(yyvsp[0].fval);
	}
	break;
	
	case 297:
//#line 1311 "VRML97.y"
	{
		ElevationGridNode *elev = new ElevationGridNode();
		elev->setName(GetDEFName());
		ParserAddNode(elev);
		ParserPushNode(VRML97_ELEVATIONGRID, elev);
	}
	break;
	
	case 298:
//#line 1321 "VRML97.y"
	{
		ElevationGridNode *elev = (ElevationGridNode *)ParserGetCurrentNode();
		elev->initialize();
		ParserPopNode();
	}
	break;
	
	case 301:
//#line 1341 "VRML97.y"
	{
		ParserPushNode(VRML97_EXTRUSION_CROSSSECTION, ParserGetCurrentNode());
	}
	break;
	
	case 302:
//#line 1348 "VRML97.y"
	{
		ParserPushNode(VRML97_EXTRUSION_ORIENTATION, ParserGetCurrentNode());
	}
	break;
	
	case 303:
//#line 1355 "VRML97.y"
	{
		ParserPushNode(VRML97_EXTRUSION_SCALE, ParserGetCurrentNode());
	}
	break;
	
	case 304:
//#line 1362 "VRML97.y"
	{
		ParserPushNode(VRML97_EXTRUSION_SPINE, ParserGetCurrentNode());
	}
	break;
	
	case 305:
//#line 1369 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setBeginCap(yyvsp[0].ival);
	}
	break;
	
	case 306:
//#line 1373 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setCCW(yyvsp[0].ival);
	}
	break;
	
	case 307:
//#line 1377 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setConvex(yyvsp[0].ival);
	}
	break;
	
	case 308:
//#line 1381 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setCreaseAngle(yyvsp[0].fval);
	}
	break;
	
	case 309:
//#line 1385 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setSolid(yyvsp[0].ival);
	}
	break;
	
	case 310:
//#line 1389 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 311:
//#line 1393 "VRML97.y"
	{
		((ExtrusionNode *)ParserGetCurrentNode())->setEndCap(yyvsp[0].ival);
	}
	break;
	
	case 312:
//#line 1397 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 313:
//#line 1401 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 314:
//#line 1405 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 315:
//#line 1412 "VRML97.y"
	{
		ExtrusionNode *ex = new ExtrusionNode();
		ex->setName(GetDEFName());
		ParserAddNode(ex);
		ParserPushNode(VRML97_EXTRUSION, ex);
	}
	break;
	
	case 316:
//#line 1422 "VRML97.y"
	{
		ExtrusionNode *ex = (ExtrusionNode *)ParserGetCurrentNode();
		ex->initialize();
		ParserPopNode();
	}
	break;
	
	case 319:
//#line 1442 "VRML97.y"
	{
		((FogNode *)ParserGetCurrentNode())->setColor(gColor);
	}
	break;
	
	case 320:
//#line 1446 "VRML97.y"
	{
		((FogNode *)ParserGetCurrentNode())->setFogType(yyvsp[0].sval);
	}
	break;
	
	case 321:
//#line 1450 "VRML97.y"
	{
		((FogNode *)ParserGetCurrentNode())->setVisibilityRange(yyvsp[0].fval);
	}
	break;
	
	case 322:
//#line 1457 "VRML97.y"
	{
		FogNode *fog = new FogNode();
		fog->setName(GetDEFName());
		ParserAddNode(fog);
		ParserPushNode(VRML97_FOG, fog);
	}
	break;
	
	case 323:
//#line 1467 "VRML97.y"
	{
		FogNode *fog = (FogNode *)ParserGetCurrentNode();
		fog->initialize();
		ParserPopNode();
	}
	break;
	
	case 326:
//#line 1487 "VRML97.y"
	{
		ParserPushNode(VRML97_FONTSTYLE_JUSTIFY, ParserGetCurrentNode());
	}
	break;
	
	case 327:
//#line 1494 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setFamily(yyvsp[0].sval);
	}
	break;
	
	case 328:
//#line 1498 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setHorizontal(yyvsp[0].ival);
	}
	break;
	
	case 329:
//#line 1502 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 330:
//#line 1506 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setLanguage(yyvsp[0].sval);
	}
	break;
	
	case 331:
//#line 1510 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setLeftToRight(yyvsp[0].ival);
	}
	break;
	
	case 332:
//#line 1514 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setSize(yyvsp[0].fval);
	}
	break;
	
	case 333:
//#line 1518 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setSpacing(yyvsp[0].fval);
	}
	break;
	
	case 334:
//#line 1522 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setStyle(yyvsp[0].sval);
	}
	break;
	
	case 335:
//#line 1526 "VRML97.y"
	{
		((FontStyleNode *)ParserGetCurrentNode())->setTopToBottom(yyvsp[0].ival);
	}
	break;
	
	case 336:
//#line 1533 "VRML97.y"
	{
		FontStyleNode *fs = new FontStyleNode();
		fs->setName(GetDEFName());
		ParserAddNode(fs);
		ParserPushNode(VRML97_FONTSTYLE, fs);
	}
	break;
	
	case 337:
//#line 1543 "VRML97.y"
	{
		FontStyleNode *fs = (FontStyleNode *)ParserGetCurrentNode();
		fs->initialize();
		ParserPopNode();
	}
	break;
	
	case 343:
//#line 1569 "VRML97.y"
	{
		GroupNode *group = new GroupNode();
		group->setName(GetDEFName());
		ParserAddNode(group);
		ParserPushNode(VRML97_GROUP, group);
	}
	break;
	
	case 344:
//#line 1579 "VRML97.y"
	{
		GroupNode *group = (GroupNode *)ParserGetCurrentNode();
		group->initialize();
		ParserPopNode();
	}
	break;
	
	case 347:
//#line 1599 "VRML97.y"
	{
		ParserPushNode(VRML97_IMAGETEXTURE_URL, ParserGetCurrentNode());
	}
	break;
	
	case 348:
//#line 1606 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 349:
//#line 1610 "VRML97.y"
	{
		((ImageTextureNode *)ParserGetCurrentNode())->setRepeatS(yyvsp[0].ival);
	}
	break;
	
	case 350:
//#line 1614 "VRML97.y"
	{
		((ImageTextureNode *)ParserGetCurrentNode())->setRepeatT(yyvsp[0].ival);
	}
	break;
	
	case 351:
//#line 1621 "VRML97.y"
	{
		ImageTextureNode *imgTexture = new ImageTextureNode();
		imgTexture->setName(GetDEFName());
		ParserAddNode(imgTexture);
		ParserPushNode(VRML97_IMAGETEXTURE, imgTexture);
	}
	break;
	
	case 352:
//#line 1631 "VRML97.y"
	{
		ImageTextureNode *imgTexture = (ImageTextureNode *)ParserGetCurrentNode();
		imgTexture->initialize();
		ParserPopNode();
	}
	break;
	
	case 355:
//#line 1651 "VRML97.y"
	{
		ParserPushNode(VRML97_COLOR_INDEX, ParserGetCurrentNode());
	}
	break;
	
	case 356:
//#line 1658 "VRML97.y"
	{
		ParserPushNode(VRML97_COORDINATE_INDEX, ParserGetCurrentNode());
	}
	break;
	
	case 357:
//#line 1665 "VRML97.y"
	{
		ParserPushNode(VRML97_NORMAL_INDEX, ParserGetCurrentNode());
	}
	break;
	
	case 358:
//#line 1672 "VRML97.y"
	{
		ParserPushNode(VRML97_TEXTURECOODINATE_INDEX, ParserGetCurrentNode());
	}
	break;
	
	case 371:
//#line 1691 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setCCW(yyvsp[0].ival);
	}
	break;
	
	case 372:
//#line 1695 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setConvex(yyvsp[0].ival);
	}
	break;
	
	case 373:
//#line 1699 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setSolid(yyvsp[0].ival);
	}
	break;
	
	case 374:
//#line 1703 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setCreaseAngle(yyvsp[0].fval);
	}
	break;
	
	case 375:
//#line 1707 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 376:
//#line 1711 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setColorPerVertex(yyvsp[0].ival);
	}
	break;
	
	case 377:
//#line 1715 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 378:
//#line 1719 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 379:
//#line 1723 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 380:
//#line 1727 "VRML97.y"
	{
		((IndexedFaceSetNode *)ParserGetCurrentNode())->setNormalPerVertex(yyvsp[0].ival);
	}
	break;
	
	case 381:
//#line 1734 "VRML97.y"
	{
		IndexedFaceSetNode	*idxFaceset = new IndexedFaceSetNode();
		idxFaceset->setName(GetDEFName());
		ParserAddNode(idxFaceset);
		ParserPushNode(VRML97_INDEXEDFACESET, idxFaceset);
	}
	break;
	
	case 382:
//#line 1744 "VRML97.y"
	{
		IndexedFaceSetNode *idxFaceset = (IndexedFaceSetNode *)ParserGetCurrentNode();
		idxFaceset->initialize();
		ParserPopNode();
	}
	break;
	
	case 391:
//#line 1770 "VRML97.y"
	{
		((IndexedLineSetNode *)ParserGetCurrentNode())->setColorPerVertex(yyvsp[0].ival);
	}
	break;
	
	case 392:
//#line 1774 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 393:
//#line 1778 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 394:
//#line 1785 "VRML97.y"
	{
		IndexedLineSetNode	*idxLineset = new IndexedLineSetNode();
		idxLineset->setName(GetDEFName());
		ParserAddNode(idxLineset);
		ParserPushNode(VRML97_INDEXEDLINESET, idxLineset);
	}
	break;
	
	case 395:
//#line 1795 "VRML97.y"
	{
		IndexedLineSetNode *idxLineset = (IndexedLineSetNode *)ParserGetCurrentNode();
		idxLineset->initialize();
		ParserPopNode();
	}
	break;
	
	case 398:
//#line 1815 "VRML97.y"
	{
		ParserPushNode(VRML97_INLINE_URL, ParserGetCurrentNode());
	}
	break;
	
	case 399:
//#line 1822 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 402:
//#line 1831 "VRML97.y"
	{
		InlineNode *inlineNode = new InlineNode();
		inlineNode->setName(GetDEFName());
		ParserAddNode(inlineNode);
		ParserPushNode(VRML97_INLINE, inlineNode);
	}
	break;
	
	case 403:
//#line 1841 "VRML97.y"
	{
		InlineNode *inlineNode = (InlineNode *)ParserGetCurrentNode();
		//inlineNode->initialize();
		ParserPopNode();
	}
	break;
	
	case 406:
//#line 1861 "VRML97.y"
	{
		ParserPushNode(VRML97_LOD_RANGE, ParserGetCurrentNode());
	}
	break;
	
	case 407:
//#line 1869 "VRML97.y"
	{
		ParserPushNode(VRML97_LOD_LEVEL, ParserGetCurrentNode());
	}
	break;
	
	case 408:
//#line 1876 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 409:
//#line 1880 "VRML97.y"
	{
		((LODNode *)ParserGetCurrentNode())->setCenter(gVec3f);
	}
	break;
	
	case 410:
//#line 1884 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 411:
//#line 1888 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 412:
//#line 1895 "VRML97.y"
	{
		LODNode	*lod = new LODNode();
		lod->setName(GetDEFName());
		ParserAddNode(lod);
		ParserPushNode(VRML97_INLINE, lod);
	}
	break;
	
	case 413:
//#line 1905 "VRML97.y"
	{
		LODNode	*lod = (LODNode *)ParserGetCurrentNode();
		lod->initialize();
		ParserPopNode();
	}
	break;
	
	case 416:
//#line 1925 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setAmbientIntensity(yyvsp[0].fval);
	}
	break;
	
	case 417:
//#line 1929 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setDiffuseColor(gColor);
	}
	break;
	
	case 418:
//#line 1933 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setEmissiveColor(gColor);
	}
	break;
	
	case 419:
//#line 1937 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setShininess(yyvsp[0].fval);
	}
	break;
	
	case 420:
//#line 1941 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setSpecularColor(gColor);
	}
	break;
	
	case 421:
//#line 1945 "VRML97.y"
	{
		((MaterialNode *)ParserGetCurrentNode())->setTransparency(yyvsp[0].fval);
	}
	break;
	
	case 422:
//#line 1952 "VRML97.y"
	{
		MaterialNode *material = new MaterialNode();
		material->setName(GetDEFName());
		ParserAddNode(material);
		ParserPushNode(VRML97_MATERIAL, material);
	}
	break;
	
	case 423:
//#line 1962 "VRML97.y"
	{
		MaterialNode *material = (MaterialNode *)ParserGetCurrentNode();
		material->initialize();
		ParserPopNode();
	}
	break;
	
	case 426:
//#line 1982 "VRML97.y"
	{
		ParserPushNode(VRML97_MOVIETEXTURE_URL, ParserGetCurrentNode());
	}
	break;
	
	case 427:
//#line 1989 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setLoop(yyvsp[0].ival);
	}
	break;
	
	case 428:
//#line 1993 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setSpeed(yyvsp[0].fval);
	}
	break;
	
	case 429:
//#line 1997 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setStartTime(yyvsp[0].fval);
	}
	break;
	
	case 430:
//#line 2001 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setStopTime(yyvsp[0].fval);
	}
	break;
	
	case 431:
//#line 2005 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 432:
//#line 2009 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setRepeatS(yyvsp[0].ival);
	}
	break;
	
	case 433:
//#line 2013 "VRML97.y"
	{
		((MovieTextureNode *)ParserGetCurrentNode())->setRepeatT(yyvsp[0].ival);
	}
	break;
	
	case 434:
//#line 2020 "VRML97.y"
	{
		MovieTextureNode *movieTexture = new MovieTextureNode();
		movieTexture->setName(GetDEFName());
		ParserAddNode(movieTexture);
		ParserPushNode(VRML97_MOVIETEXTURE, movieTexture);
	}
	break;
	
	case 435:
//#line 2030 "VRML97.y"
	{
		MovieTextureNode *movieTexture = (MovieTextureNode *)ParserGetCurrentNode();
		movieTexture->initialize();
		ParserPopNode();
	}
	break;
	
	case 438:
//#line 2050 "VRML97.y"
	{
		ParserPushNode(VRML97_NAVIGATIONINFO_AVATARSIZE, ParserGetCurrentNode());
	}
	break;
	
	case 439:
//#line 2057 "VRML97.y"
	{
		ParserPushNode(VRML97_NAVIGATIONINFO_TYPE, ParserGetCurrentNode());
	}
	break;
	
	case 440:
//#line 2064 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 441:
//#line 2068 "VRML97.y"
	{
		((NavigationInfoNode *)ParserGetCurrentNode())->setHeadlight(yyvsp[0].ival);
	}
	break;
	
	case 442:
//#line 2072 "VRML97.y"
	{
		((NavigationInfoNode *)ParserGetCurrentNode())->setSpeed(yyvsp[0].fval);
	}
	break;
	
	case 443:
//#line 2076 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 444:
//#line 2080 "VRML97.y"
	{
		((NavigationInfoNode *)ParserGetCurrentNode())->setVisibilityLimit(yyvsp[0].fval);
	}
	break;
	
	case 445:
//#line 2087 "VRML97.y"
	{
		NavigationInfoNode *navInfo = new NavigationInfoNode();
		navInfo->setName(GetDEFName());
		ParserAddNode(navInfo);
		ParserPushNode(VRML97_NAVIGATIONINFO, navInfo);
	}
	break;
	
	case 446:
//#line 2097 "VRML97.y"
	{
		NavigationInfoNode *navInfo = (NavigationInfoNode *)ParserGetCurrentNode();
		navInfo->initialize();
		ParserPopNode();
	}
	break;
	
	case 450:
//#line 2121 "VRML97.y"
	{
		NormalNode *normal = new NormalNode();
		normal->setName(GetDEFName());
		ParserAddNode(normal);
		ParserPushNode(VRML97_NORMAL, normal);
	}
	break;
	
	case 451:
//#line 2131 "VRML97.y"
	{
		NormalNode *normal = (NormalNode *)ParserGetCurrentNode();
		normal->initialize();
		ParserPopNode();
	}
	break;
	
	case 454:
//#line 2151 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 455:
//#line 2155 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 456:
//#line 2159 "VRML97.y"
	{
	}
	break;
	
	case 457:
//#line 2165 "VRML97.y"
	{
		NormalInterpolatorNode *normInterp = new NormalInterpolatorNode();
		normInterp->setName(GetDEFName());
		ParserAddNode(normInterp);
		ParserPushNode(VRML97_NORMALINTERPOLATOR, normInterp);
	}
	break;
	
	case 458:
//#line 2175 "VRML97.y"
	{
		NormalInterpolatorNode *normInterp = (NormalInterpolatorNode *)ParserGetCurrentNode();
		normInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 461:
//#line 2195 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 462:
//#line 2199 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 463:
//#line 2203 "VRML97.y"
	{
	}
	break;
	
	case 464:
//#line 2209 "VRML97.y"
	{
		OrientationInterpolatorNode *oriInterp = new OrientationInterpolatorNode();
		oriInterp->setName(GetDEFName());
		ParserAddNode(oriInterp);
		ParserPushNode(VRML97_ORIENTATIONINTERPOLATOR, oriInterp);
	}
	break;
	
	case 465:
//#line 2219 "VRML97.y"
	{
		OrientationInterpolatorNode *oriInterp = (OrientationInterpolatorNode *)ParserGetCurrentNode();
		oriInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 468:
//#line 2239 "VRML97.y"
	{
		ParserPushNode(VRML97_PIXELTEXTURE_IMAGE, ParserGetCurrentNode());
	}
	break;
	
	case 469:
//#line 2246 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 470:
//#line 2250 "VRML97.y"
	{
		((PixelTextureNode *)ParserGetCurrentNode())->setRepeatS(yyvsp[0].ival);
	}
	break;
	
	case 471:
//#line 2254 "VRML97.y"
	{
		((PixelTextureNode *)ParserGetCurrentNode())->setRepeatT(yyvsp[0].ival);
	}
	break;
	
	case 472:
//#line 2261 "VRML97.y"
	{
		PixelTextureNode *pixTexture = new PixelTextureNode();
		pixTexture->setName(GetDEFName());
		ParserAddNode(pixTexture);
		ParserPushNode(VRML97_PIXELTEXTURE, pixTexture);
	}
	break;
	
	case 473:
//#line 2271 "VRML97.y"
	{
		PixelTextureNode *pixTexture = (PixelTextureNode *)ParserGetCurrentNode();
		pixTexture->initialize();
		ParserPopNode();
	}
	break;
	
	case 476:
//#line 2291 "VRML97.y"
	{
		((PlaneSensorNode *)ParserGetCurrentNode())->setAutoOffset(yyvsp[0].ival);
	}
	break;
	
	case 477:
//#line 2295 "VRML97.y"
	{
		((PlaneSensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 478:
//#line 2299 "VRML97.y"
	{
		((PlaneSensorNode *)ParserGetCurrentNode())->setMaxPosition(gVec2f);
	}
	break;
	
	case 479:
//#line 2303 "VRML97.y"
	{
		((PlaneSensorNode *)ParserGetCurrentNode())->setMinPosition(gVec2f);
	}
	break;
	
	case 480:
//#line 2307 "VRML97.y"
	{
		((PlaneSensorNode *)ParserGetCurrentNode())->setOffset(gVec3f);
	}
	break;
	
	case 481:
//#line 2314 "VRML97.y"
	{
		PlaneSensorNode *psensor = new PlaneSensorNode();
		psensor->setName(GetDEFName());
		ParserAddNode(psensor);
		ParserPushNode(VRML97_PLANESENSOR, psensor);
	}
	break;
	
	case 482:
//#line 2324 "VRML97.y"
	{
		PlaneSensorNode *psensor = (PlaneSensorNode *)ParserGetCurrentNode();
		psensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 485:
//#line 2345 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setAmbientIntensity(yyvsp[0].fval);
	}
	break;
	
	case 486:
//#line 2349 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setAttenuation(gVec3f);
	}
	break;
	
	case 487:
//#line 2353 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setColor(gColor);
	}
	break;
	
	case 488:
//#line 2357 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setIntensity(yyvsp[0].fval);
	}
	break;
	
	case 489:
//#line 2361 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setLocation(gVec3f);
	}
	break;
	
	case 490:
//#line 2365 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setOn(yyvsp[0].ival);
	}
	break;
	
	case 491:
//#line 2369 "VRML97.y"
	{
		((PointLightNode *)ParserGetCurrentNode())->setRadius(yyvsp[0].fval);
	}
	break;
	
	case 492:
//#line 2376 "VRML97.y"
	{
		PointLightNode *pointLight = new PointLightNode();
		pointLight->setName(GetDEFName());
		ParserAddNode(pointLight);
		ParserPushNode(VRML97_POINTLIGHT, pointLight);
	}
	break;
	
	case 493:
//#line 2386 "VRML97.y"
	{
		PointLightNode *pointLight = (PointLightNode *)ParserGetCurrentNode();
		pointLight->initialize();
		ParserPopNode();
	}
	break;
	
	case 502:
//#line 2416 "VRML97.y"
	{
		PointSetNode *pset = new PointSetNode();
		pset->setName(GetDEFName());
		ParserAddNode(pset);
		ParserPushNode(VRML97_POINTSET, pset);
	}
	break;
	
	case 503:
//#line 2426 "VRML97.y"
	{
		PointSetNode *pset = (PointSetNode *)ParserGetCurrentNode();
		pset->initialize();
		ParserPopNode();
	}
	break;
	
	case 506:
//#line 2446 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 507:
//#line 2450 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 508:
//#line 2454 "VRML97.y"
	{
	}
	break;
	
	case 509:
//#line 2460 "VRML97.y"
	{
		PositionInterpolatorNode *posInterp = new PositionInterpolatorNode();
		posInterp->setName(GetDEFName());
		ParserAddNode(posInterp);
		ParserPushNode(VRML97_POSITIONINTERPOLATOR, posInterp);
	}
	break;
	
	case 510:
//#line 2470 "VRML97.y"
	{
		PositionInterpolatorNode *posInterp = (PositionInterpolatorNode *)ParserGetCurrentNode();
		posInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 513:
//#line 2490 "VRML97.y"
	{
		((ProximitySensorNode *)ParserGetCurrentNode())->setCenter(gVec3f);
	}
	break;
	
	case 514:
//#line 2494 "VRML97.y"
	{
		((ProximitySensorNode *)ParserGetCurrentNode())->setSize(gVec3f);
	}
	break;
	
	case 515:
//#line 2498 "VRML97.y"
	{
		((ProximitySensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 516:
//#line 2505 "VRML97.y"
	{
		ProximitySensorNode *psensor = new ProximitySensorNode();
		psensor->setName(GetDEFName());
		ParserAddNode(psensor);
		ParserPushNode(VRML97_PROXIMITYSENSOR, psensor);
	}
	break;
	
	case 517:
//#line 2515 "VRML97.y"
	{
		ProximitySensorNode *psensor = (ProximitySensorNode *)ParserGetCurrentNode();
		psensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 520:
//#line 2535 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 521:
//#line 2539 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 522:
//#line 2543 "VRML97.y"
	{
	}
	break;
	
	case 523:
//#line 2549 "VRML97.y"
	{
		ScalarInterpolatorNode *scalarInterp = new ScalarInterpolatorNode();
		scalarInterp->setName(GetDEFName());
		ParserAddNode(scalarInterp);
		ParserPushNode(VRML97_SCALARINTERPOLATOR, scalarInterp);
	}
	break;
	
	case 524:
//#line 2559 "VRML97.y"
	{
		ScalarInterpolatorNode *scalarInterp = (ScalarInterpolatorNode *)ParserGetCurrentNode();
		scalarInterp->initialize();
		ParserPopNode();
	}
	break;
	
	case 527:
//#line 2579 "VRML97.y"
	{
		ParserPushNode(VRML97_SCRIPT_URL, ParserGetCurrentNode());
	}
	break;
	
	case 528:
//#line 2586 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 529:
//#line 2590 "VRML97.y"
	{
		((ScriptNode *)ParserGetCurrentNode())->setDirectOutput(yyvsp[0].ival);
	}
	break;
	
	case 530:
//#line 2594 "VRML97.y"
	{
		((ScriptNode *)ParserGetCurrentNode())->setMustEvaluate(yyvsp[0].ival);
	}
	break;
	
	case 531:
//#line 2603 "VRML97.y"
	{
		SFBool *value = new SFBool();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 532:
//#line 2609 "VRML97.y"
	{
		SFFloat *value = new SFFloat();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 533:
//#line 2615 "VRML97.y"
	{
		SFInt32 *value = new SFInt32();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 534:
//#line 2621 "VRML97.y"
	{
		SFTime *value = new SFTime();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 535:
//#line 2627 "VRML97.y"
	{
		SFRotation *value = new SFRotation();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 536:
//#line 2641 "VRML97.y"
	{
		SFColor *value = new SFColor();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 537:
//#line 2647 "VRML97.y"
	{
		SFImage *value = new SFImage();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 538:
//#line 2653 "VRML97.y"
	{
		SFString *value = new SFString();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 539:
//#line 2659 "VRML97.y"
	{
		SFVec2f *value = new SFVec2f();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 540:
//#line 2665 "VRML97.y"
	{
		SFVec3f *value = new SFVec3f();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 541:
//#line 2676 "VRML97.y"
	{
		MFFloat *value = new MFFloat();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 542:
//#line 2682 "VRML97.y"
	{
		MFInt32 *value = new MFInt32();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 543:
//#line 2688 "VRML97.y"
	{
		MFTime *value = new MFTime();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 544:
//#line 2694 "VRML97.y"
	{
		MFRotation *value = new MFRotation();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 545:
//#line 2708 "VRML97.y"
	{
		MFColor *value = new MFColor();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 546:
//#line 2714 "VRML97.y"
	{
		MFString *value = new MFString();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 547:
//#line 2720 "VRML97.y"
	{
		MFVec2f *value = new MFVec2f();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 548:
//#line 2726 "VRML97.y"
	{
		MFVec3f *value = new MFVec3f();
		((ScriptNode *)ParserGetCurrentNode())->addEventIn(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 549:
//#line 2737 "VRML97.y"
	{
		SFBool *value = new SFBool();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 550:
//#line 2743 "VRML97.y"
	{
		SFFloat *value = new SFFloat();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 551:
//#line 2749 "VRML97.y"
	{
		SFInt32 *value = new SFInt32();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 552:
//#line 2755 "VRML97.y"
	{
		SFTime *value = new SFTime();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 553:
//#line 2761 "VRML97.y"
	{
		SFRotation *value = new SFRotation();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 554:
//#line 2775 "VRML97.y"
	{
		SFColor *value = new SFColor();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 555:
//#line 2781 "VRML97.y"
	{
		SFImage *value = new SFImage();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 556:
//#line 2787 "VRML97.y"
	{
		SFString *value = new SFString();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 557:
//#line 2793 "VRML97.y"
	{
		SFVec2f *value = new SFVec2f();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 558:
//#line 2799 "VRML97.y"
	{
		SFVec3f *value = new SFVec3f();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 559:
//#line 2810 "VRML97.y"
	{
		MFFloat *value = new MFFloat();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 560:
//#line 2816 "VRML97.y"
	{
		MFInt32 *value = new MFInt32();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 561:
//#line 2822 "VRML97.y"
	{
		MFTime *value = new MFTime();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 562:
//#line 2828 "VRML97.y"
	{
		MFRotation *value = new MFRotation();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 563:
//#line 2842 "VRML97.y"
	{
		MFColor *value = new MFColor();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 564:
//#line 2848 "VRML97.y"
	{
		MFString *value = new MFString();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 565:
//#line 2854 "VRML97.y"
	{
		MFVec2f *value = new MFVec2f();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 566:
//#line 2860 "VRML97.y"
	{
		MFVec3f *value = new MFVec3f();
		((ScriptNode *)ParserGetCurrentNode())->addEventOut(yyvsp[0].sval, value);
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 567:
//#line 2871 "VRML97.y"
	{
		SFBool *value = new SFBool(yyvsp[0].ival);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 568:
//#line 2877 "VRML97.y"
	{
		SFFloat *value = new SFFloat(yyvsp[0].fval);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 569:
//#line 2883 "VRML97.y"
	{
		SFInt32 *value = new SFInt32(yyvsp[0].ival);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 570:
//#line 2889 "VRML97.y"
	{
		SFTime *value = new SFTime(yyvsp[0].fval);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 571:
//#line 2895 "VRML97.y"
	{
		SFRotation *value = new SFRotation(gRotation);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 572:
//#line 2902 "VRML97.y"
	{
		SFNode *value = new SFNode();
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 573:
//#line 2909 "VRML97.y"
	{
		Node *node = GetParserObject()->findNode(yyvsp[0].sval);
		SFNode *value = new SFNode(node);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-2].sval, value);
		delete[] yyvsp[-2].sval;
		delete[] yyvsp[0].sval;
	}
	break;
	
	case 574:
//#line 2917 "VRML97.y"
	{
		SFColor *value = new SFColor(gColor);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 575:
//#line 2931 "VRML97.y"
	{
		SFString *value = new SFString(yyvsp[0].sval);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 576:
//#line 2937 "VRML97.y"
	{
		SFVec2f *value = new SFVec2f(gVec2f);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 577:
//#line 2943 "VRML97.y"
	{
		SFVec3f *value = new SFVec3f(gVec3f);
		((ScriptNode *)ParserGetCurrentNode())->addField(yyvsp[-1].sval, value);
		delete[] yyvsp[-1].sval;
	}
	break;
	
	case 578:
//#line 2953 "VRML97.y"
	{
		ScriptNode *script = new ScriptNode();
		script->setName(GetDEFName());
		ParserAddNode(script);
		ParserPushNode(VRML97_SCRIPT, script);
	}
	break;
	
	case 579:
//#line 2963 "VRML97.y"
	{
		ScriptNode *script = (ScriptNode *)ParserGetCurrentNode();
		script->initialize();
		ParserPopNode();
	}
	break;
	
	case 588:
//#line 2993 "VRML97.y"
	{
		ShapeNode *shape = new ShapeNode();
		shape->setName(GetDEFName());
		ParserAddNode(shape);
		ParserPushNode(VRML97_SHAPE, shape);
	}
	break;
	
	case 589:
//#line 3003 "VRML97.y"
	{
		ShapeNode *shape = (ShapeNode *)ParserGetCurrentNode();
		shape->initialize();
		ParserPopNode();
	}
	break;
	
	case 592:
//#line 3023 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setDirection(gVec3f);
	}
	break;
	
	case 593:
//#line 3027 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setIntensity(yyvsp[0].fval);
	}
	break;
	
	case 594:
//#line 3031 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setLocation(gVec3f);
	}
	break;
	
	case 595:
//#line 3035 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setMinBack(yyvsp[0].fval);
	}
	break;
	
	case 596:
//#line 3039 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setMaxFront(yyvsp[0].fval);
	}
	break;
	
	case 597:
//#line 3043 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setMinBack(yyvsp[0].fval);
	}
	break;
	
	case 598:
//#line 3047 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setMinFront(yyvsp[0].fval);
	}
	break;
	
	case 599:
//#line 3051 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setPriority(yyvsp[0].fval);
	}
	break;
	
	case 604:
//#line 3059 "VRML97.y"
	{
		((SoundNode *)ParserGetCurrentNode())->setSpatialize(yyvsp[0].ival);
	}
	break;
	
	case 605:
//#line 3066 "VRML97.y"
	{
		SoundNode *sound = new SoundNode();
		sound->setName(GetDEFName());
		ParserAddNode(sound);
		ParserPushNode(VRML97_SOUND, sound);
	}
	break;
	
	case 606:
//#line 3076 "VRML97.y"
	{
		SoundNode *sound = (SoundNode *)ParserGetCurrentNode();
		sound->initialize();
		ParserPopNode();
	}
	break;
	
	case 609:
//#line 3096 "VRML97.y"
	{
		((SphereNode *)ParserGetCurrentNode())->setRadius(yyvsp[0].fval);
	}
	break;
	
	case 610:
//#line 3103 "VRML97.y"
	{
		SphereNode *sphere = new SphereNode();
		sphere->setName(GetDEFName());
		ParserAddNode(sphere);
		ParserPushNode(VRML97_SPHERE, sphere);
	}
	break;
	
	case 611:
//#line 3113 "VRML97.y"
	{
		SphereNode *sphere = (SphereNode *)ParserGetCurrentNode();
		sphere->initialize();
		ParserPopNode();
	}
	break;
	
	case 614:
//#line 3133 "VRML97.y"
	{
		((SphereSensorNode *)ParserGetCurrentNode())->setAutoOffset(yyvsp[0].ival);
	}
	break;
	
	case 615:
//#line 3137 "VRML97.y"
	{
		((SphereSensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 616:
//#line 3141 "VRML97.y"
	{
		((SphereSensorNode *)ParserGetCurrentNode())->setOffset(gRotation);
	}
	break;
	
	case 617:
//#line 3148 "VRML97.y"
	{
		SphereSensorNode *spsensor = new SphereSensorNode();
		spsensor->setName(GetDEFName());
		ParserAddNode(spsensor);
		ParserPushNode(VRML97_SPHERESENSOR, spsensor);
	}
	break;
	
	case 618:
//#line 3158 "VRML97.y"
	{
		SphereSensorNode *spsensor = (SphereSensorNode *)ParserGetCurrentNode();
		spsensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 621:
//#line 3178 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setAmbientIntensity(yyvsp[0].fval);
	}
	break;
	
	case 622:
//#line 3182 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setAttenuation(gVec3f);
	}
	break;
	
	case 623:
//#line 3186 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setBeamWidth(yyvsp[0].fval);
	}
	break;
	
	case 624:
//#line 3190 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setColor(gColor);
	}
	break;
	
	case 625:
//#line 3194 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setCutOffAngle(yyvsp[0].fval);
	}
	break;
	
	case 626:
//#line 3198 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setDirection(gVec3f);
	}
	break;
	
	case 627:
//#line 3202 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setIntensity(yyvsp[0].fval);
	}
	break;
	
	case 628:
//#line 3206 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setLocation(gVec3f);
	}
	break;
	
	case 629:
//#line 3210 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setOn(yyvsp[0].ival);
	}
	break;
	
	case 630:
//#line 3214 "VRML97.y"
	{
		((SpotLightNode *)ParserGetCurrentNode())->setRadius(yyvsp[0].fval);
	}
	break;
	
	case 631:
//#line 3221 "VRML97.y"
	{
		SpotLightNode *spotLight = new SpotLightNode();
		spotLight->setName(GetDEFName());
		ParserAddNode(spotLight);
		ParserPushNode(VRML97_SPOTLIGHT, spotLight);
	}
	break;
	
	case 632:
//#line 3231 "VRML97.y"
	{
		SpotLightNode *spotLight = (SpotLightNode *)ParserGetCurrentNode();
		spotLight->initialize();
		ParserPopNode();
	}
	break;
	
	case 635:
//#line 3251 "VRML97.y"
	{
		ParserPushNode(VRML97_SWITCH_CHOICE, ParserGetCurrentNode());
	}
	break;
	
	case 636:
//#line 3258 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 637:
//#line 3262 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 638:
//#line 3266 "VRML97.y"
	{
		((SwitchNode *)ParserGetCurrentNode())->setWhichChoice(yyvsp[0].ival);
	}
	break;
	
	case 639:
//#line 3274 "VRML97.y"
	{
		SwitchNode *switchNode = new SwitchNode();
		switchNode->setName(GetDEFName());
		ParserAddNode(switchNode);
		ParserPushNode(VRML97_SWITCH, switchNode);
	}
	break;
	
	case 640:
//#line 3284 "VRML97.y"
	{
		SwitchNode *switchNode = (SwitchNode *)ParserGetCurrentNode();
		switchNode->initialize();
		ParserPopNode();
	}
	break;
	
	case 643:
//#line 3304 "VRML97.y"
	{
		ParserPushNode(VRML97_TEXT_STRING, ParserGetCurrentNode());
	}
	break;
	
	case 644:
//#line 3311 "VRML97.y"
	{
		ParserPushNode(VRML97_TEXT_LENGTH, ParserGetCurrentNode());
	}
	break;
	
	case 645:
//#line 3318 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 649:
//#line 3325 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 650:
//#line 3329 "VRML97.y"
	{
		((TextNode *)ParserGetCurrentNode())->setMaxExtent(yyvsp[0].fval);
	}
	break;
	
	case 651:
//#line 3337 "VRML97.y"
	{
		TextNode *text = new TextNode();
		text->setName(GetDEFName());
		ParserAddNode(text);
		ParserPushNode(VRML97_TEXT, text);
	}
	break;
	
	case 652:
//#line 3347 "VRML97.y"
	{
		TextNode *text = (TextNode *)ParserGetCurrentNode();
		text->initialize();
		ParserPopNode();
	}
	break;
	
	case 656:
//#line 3372 "VRML97.y"
	{
		TextureCoordinateNode *texCoord = new TextureCoordinateNode();
		texCoord->setName(GetDEFName());
		ParserAddNode(texCoord);
		ParserPushNode(VRML97_TEXTURECOODINATE, texCoord);
	}
	break;
	
	case 657:
//#line 3382 "VRML97.y"
	{
		TextureCoordinateNode *texCoord = (TextureCoordinateNode *)ParserGetCurrentNode();
		texCoord->initialize();
		ParserPopNode();
	}
	break;
	
	case 660:
//#line 3402 "VRML97.y"
	{
		((TextureTransformNode *)ParserGetCurrentNode())->setCenter(gVec2f);
	}
	break;
	
	case 661:
//#line 3406 "VRML97.y"
	{
		((TextureTransformNode *)ParserGetCurrentNode())->setRotation(yyvsp[0].fval);
	}
	break;
	
	case 662:
//#line 3410 "VRML97.y"
	{
		((TextureTransformNode *)ParserGetCurrentNode())->setScale(gVec2f);
	}
	break;
	
	case 663:
//#line 3414 "VRML97.y"
	{
		((TextureTransformNode *)ParserGetCurrentNode())->setTranslation(gVec2f);
	}
	break;
	
	case 664:
//#line 3422 "VRML97.y"
	{
		TextureTransformNode *textureTransform = new TextureTransformNode();
		textureTransform->setName(GetDEFName());
		ParserAddNode(textureTransform);
		ParserPushNode(VRML97_TEXTURETRANSFORM, textureTransform);
	}
	break;
	
	case 665:
//#line 3432 "VRML97.y"
	{
		TextureTransformNode *textureTransform = (TextureTransformNode *)ParserGetCurrentNode();
		textureTransform->initialize();
		ParserPopNode();
	}
	break;
	
	case 668:
//#line 3452 "VRML97.y"
	{
		((TimeSensorNode *)ParserGetCurrentNode())->setCycleInterval(yyvsp[0].fval);
	}
	break;
	
	case 669:
//#line 3456 "VRML97.y"
	{
		((TimeSensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 670:
//#line 3460 "VRML97.y"
	{
		((TimeSensorNode *)ParserGetCurrentNode())->setLoop(yyvsp[0].ival);
	}
	break;
	
	case 671:
//#line 3464 "VRML97.y"
	{
		((TimeSensorNode *)ParserGetCurrentNode())->setStartTime(yyvsp[0].fval);
	}
	break;
	
	case 672:
//#line 3468 "VRML97.y"
	{
		((TimeSensorNode *)ParserGetCurrentNode())->setStopTime(yyvsp[0].fval);
	}
	break;
	
	case 673:
//#line 3476 "VRML97.y"
	{
		TimeSensorNode *tsensor = new TimeSensorNode();
		tsensor->setName(GetDEFName());
		ParserAddNode(tsensor);
		ParserPushNode(VRML97_TIMESENSOR, tsensor);
	}
	break;
	
	case 674:
//#line 3486 "VRML97.y"
	{
		TimeSensorNode *tsensor = (TimeSensorNode *)ParserGetCurrentNode();
		tsensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 677:
//#line 3506 "VRML97.y"
	{
		((TouchSensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 678:
//#line 3513 "VRML97.y"
	{
		TouchSensorNode *touchSensor = new TouchSensorNode();
		touchSensor->setName(GetDEFName());
		ParserAddNode(touchSensor);
		ParserPushNode(VRML97_TOUCHSENSOR, touchSensor);
	}
	break;
	
	case 679:
//#line 3523 "VRML97.y"
	{
		TouchSensorNode *touchSensor = (TouchSensorNode *)ParserGetCurrentNode();
		touchSensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 683:
//#line 3544 "VRML97.y"
	{
		((TransformNode *)ParserGetCurrentNode())->setCenter(gVec3f);
	}
	break;
	
	case 684:
//#line 3548 "VRML97.y"
	{
		((TransformNode *)ParserGetCurrentNode())->setRotation(gRotation);
	}
	break;
	
	case 685:
//#line 3552 "VRML97.y"
	{
		((TransformNode *)ParserGetCurrentNode())->setScale(gVec3f);
	}
	break;
	
	case 686:
//#line 3556 "VRML97.y"
	{
		((TransformNode *)ParserGetCurrentNode())->setScaleOrientation(gRotation);
	}
	break;
	
	case 687:
//#line 3560 "VRML97.y"
	{
		((TransformNode *)ParserGetCurrentNode())->setTranslation(gVec3f);
	}
	break;
	
	case 690:
//#line 3569 "VRML97.y"
	{
		TransformNode *transform = new TransformNode();
		transform->setName(GetDEFName());
		ParserAddNode(transform);
		ParserPushNode(VRML97_TRANSFORM, transform);
	}
	break;
	
	case 691:
//#line 3579 "VRML97.y"
	{
		TransformNode *transform = (TransformNode *)ParserGetCurrentNode();
		transform->initialize();
		ParserPopNode();
	}
	break;
	
	case 694:
//#line 3599 "VRML97.y"
	{
		((ViewpointNode *)ParserGetCurrentNode())->setFieldOfView(yyvsp[0].fval);
	}
	break;
	
	case 695:
//#line 3603 "VRML97.y"
	{
		((ViewpointNode *)ParserGetCurrentNode())->setJump(yyvsp[0].ival);
	}
	break;
	
	case 696:
//#line 3607 "VRML97.y"
	{
		((ViewpointNode *)ParserGetCurrentNode())->setOrientation(gRotation);
	}
	break;
	
	case 697:
//#line 3611 "VRML97.y"
	{
		((ViewpointNode *)ParserGetCurrentNode())->setPosition(gVec3f);
	}
	break;
	
	case 698:
//#line 3615 "VRML97.y"
	{
		((ViewpointNode *)ParserGetCurrentNode())->setDescription(yyvsp[0].sval);
	}
	break;
	
	case 699:
//#line 3622 "VRML97.y"
	{
		ViewpointNode *viewpoint = new ViewpointNode();
		viewpoint->setName(GetDEFName());
		ParserAddNode(viewpoint);
		ParserPushNode(VRML97_VIEWPOINT, viewpoint);
	}
	break;
	
	case 700:
//#line 3632 "VRML97.y"
	{
		ViewpointNode *viewpoint = (ViewpointNode *)ParserGetCurrentNode();
		viewpoint->initialize();
		ParserPopNode();
	}
	break;
	
	case 703:
//#line 3652 "VRML97.y"
	{
		((VisibilitySensorNode *)ParserGetCurrentNode())->setCenter(gVec3f);
	}
	break;
	
	case 704:
//#line 3656 "VRML97.y"
	{
		((VisibilitySensorNode *)ParserGetCurrentNode())->setEnabled(yyvsp[0].ival);
	}
	break;
	
	case 705:
//#line 3660 "VRML97.y"
	{
		((VisibilitySensorNode *)ParserGetCurrentNode())->setSize(gVec3f);
	}
	break;
	
	case 706:
//#line 3667 "VRML97.y"
	{
		VisibilitySensorNode *vsensor = new VisibilitySensorNode();
		vsensor->setName(GetDEFName());
		ParserAddNode(vsensor);
		ParserPushNode(VRML97_VISIBILITYSENSOR, vsensor);
	}
	break;
	
	case 707:
//#line 3677 "VRML97.y"
	{
		VisibilitySensorNode *vsensor = (VisibilitySensorNode *)ParserGetCurrentNode();
		vsensor->initialize();
		ParserPopNode();
	}
	break;
	
	case 710:
//#line 3697 "VRML97.y"
	{
		ParserPushNode(VRML97_WORLDINFO_INFO, ParserGetCurrentNode());
	}
	break;
	
	case 711:
//#line 3704 "VRML97.y"
	{
		ParserPopNode();
	}
	break;
	
	case 712:
//#line 3708 "VRML97.y"
	{
		((WorldInfoNode *)ParserGetCurrentNode())->setTitle(yyvsp[0].sval);
	}
	break;
	
	case 713:
//#line 3715 "VRML97.y"
	{
		WorldInfoNode *worldInfo = new WorldInfoNode();
		worldInfo->setName(GetDEFName());
		ParserAddNode(worldInfo);
		ParserPushNode(VRML97_WORLDINFO, worldInfo);
	}
	break;
	
	case 714:
//#line 3725 "VRML97.y"
	{
		WorldInfoNode *worldInfo = (WorldInfoNode *)ParserGetCurrentNode();
		worldInfo->initialize();
		ParserPopNode();
	}
	break;
	
	
	}
	
	/* Line 999 of yacc.c.  */
//#line 6201 "VRML97.tab.cpp"
	
	yyvsp -= yylen;
	yyssp -= yylen;
	
	
	YY_STACK_PRINT(yyss, yyssp);
	
	*++yyvsp = yyval;
	
	
	/* Now `shift' the result of the reduction.  Determine what state
	   that goes to, based on the state we popped back to and the rule
	   number reduced by.  */
	
	yyn = yyr1[yyn];
	
	yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
	if(0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
		yystate = yytable[yystate];
	else
		yystate = yydefgoto[yyn - YYNTOKENS];
		
	goto yynewstate;
	
	
	/*------------------------------------.
	| yyerrlab -- here on detecting error |
	`------------------------------------*/
yyerrlab:
	/* If not already recovering from an error, report this error.  */
	if(!yyerrstatus)
	{
		++yynerrs;
#if YYERROR_VERBOSE
		yyn = yypact[yystate];
		
		if(YYPACT_NINF < yyn && yyn < YYLAST)
		{
			YYSIZE_T yysize = 0;
			int yytype = YYTRANSLATE(yychar);
			const char* yyprefix;
			char *yymsg;
			int yyx;
			
			/* Start YYX at -YYN if negative to avoid negative indexes in
			   YYCHECK.  */
			int yyxbegin = yyn < 0 ? -yyn : 0;
			
			/* Stay within bounds of both yycheck and yytname.  */
			int yychecklim = YYLAST - yyn;
			int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
			int yycount = 0;
			
			yyprefix = ", expecting ";
			for(yyx = yyxbegin; yyx < yyxend; ++yyx)
				if(yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
				{
					yysize += yystrlen(yyprefix) + yystrlen(yytname [yyx]);
					yycount += 1;
					if(yycount == 5)
					{
						yysize = 0;
						break;
					}
				}
			yysize += (sizeof("syntax error, unexpected ")
			           + yystrlen(yytname[yytype]));
			yymsg = (char *) YYSTACK_ALLOC(yysize);
			if(yymsg != 0)
			{
				char *yyp = yystpcpy(yymsg, "syntax error, unexpected ");
				yyp = yystpcpy(yyp, yytname[yytype]);
				
				if(yycount < 5)
				{
					yyprefix = ", expecting ";
					for(yyx = yyxbegin; yyx < yyxend; ++yyx)
						if(yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
						{
							yyp = yystpcpy(yyp, yyprefix);
							yyp = yystpcpy(yyp, yytname[yyx]);
							yyprefix = " or ";
						}
				}
				yyerror(yymsg);
				YYSTACK_FREE(yymsg);
			}
			else
				yyerror("syntax error; also virtual memory exhausted");
		}
		else
#endif /* YYERROR_VERBOSE */
			yyerror("syntax error");
	}
	
	
	
	if(yyerrstatus == 3)
	{
		/* If just tried and failed to reuse lookahead token after an
			 error, discard it.  */
		
		/* Return failure if at end of input.  */
		if(yychar == YYEOF)
		{
			/* Pop the error token.  */
			YYPOPSTACK;
			/* Pop the rest of the stack.  */
			while(yyss < yyssp)
			{
				YYDSYMPRINTF("Error: popping", yystos[*yyssp], yyvsp, yylsp);
				yydestruct(yystos[*yyssp], yyvsp);
				YYPOPSTACK;
			}
			YYABORT;
		}
		
		YYDSYMPRINTF("Error: discarding", yytoken, &yylval, &yylloc);
		yydestruct(yytoken, &yylval);
		yychar = YYEMPTY;
		
	}
	
	/* Else will try to reuse lookahead token after shifting the error
	   token.  */
	goto yyerrlab1;
	
	
	/*----------------------------------------------------.
	| yyerrlab1 -- error raised explicitly by an action.  |
	`----------------------------------------------------*/
yyerrlab1:
	yyerrstatus = 3;	/* Each real token shifted decrements this.  */
	
	for(;;)
	{
		yyn = yypact[yystate];
		if(yyn != YYPACT_NINF)
		{
			yyn += YYTERROR;
			if(0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
			{
				yyn = yytable[yyn];
				if(0 < yyn)
					break;
			}
		}
		
		/* Pop the current state because it cannot handle the error token.  */
		if(yyssp == yyss)
			YYABORT;
			
		YYDSYMPRINTF("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		yydestruct(yystos[yystate], yyvsp);
		yyvsp--;
		yystate = *--yyssp;
		
		YY_STACK_PRINT(yyss, yyssp);
	}
	
	if(yyn == YYFINAL)
		YYACCEPT;
		
	YYDPRINTF((stderr, "Shifting error token, "));
	
	*++yyvsp = yylval;
	
	
	yystate = yyn;
	goto yynewstate;
	
	
	/*-------------------------------------.
	| yyacceptlab -- YYACCEPT comes here.  |
	`-------------------------------------*/
yyacceptlab:
	yyresult = 0;
	goto yyreturn;
	
	/*-----------------------------------.
	| yyabortlab -- YYABORT comes here.  |
	`-----------------------------------*/
yyabortlab:
	yyresult = 1;
	goto yyreturn;
	
#ifndef yyoverflow
	/*----------------------------------------------.
	| yyoverflowlab -- parser overflow comes here.  |
	`----------------------------------------------*/
yyoverflowlab:
	yyerror("parser stack overflow");
	yyresult = 2;
	/* Fall through.  */
#endif
	
yyreturn:
#ifndef yyoverflow
	if(yyss != yyssa)
		YYSTACK_FREE(yyss);
#endif
	return yyresult;
}


//#line 3732 "VRML97.y"


