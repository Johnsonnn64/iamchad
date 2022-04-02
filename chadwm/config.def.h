/* See LICENSE file for copyright and license details. */
/* appearance */
static const unsigned int borderpx       = 2;        /* border pixel of windows */
static const unsigned int default_border = 2;        /* to switch back to default border after dynamic border resizing via keybinds */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int gappih         = 60;       /* horiz inner gap between windows */
static const unsigned int gappiv         = 60;       /* vert inner gap between windows */
static const unsigned int gappoh         = 60;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 60;       /* vert outer gap between windows and screen edge */
static       int smartgaps               = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;        /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;        /* systray spacing */
static const int systraypinningfailfirst = 1;        /* 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor*/
static const int showsystray             = 0;        /* 0 means no systray */
static const int showbar                 = 1;        /* 0 means no bar */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always };
static const int showtab                 = showtab_never;
static const int toptab                  = True;
static const int topbar                  = 1;        /* 0 means bottom bar */
static const int vertpad                 = 0;        /* statusbar verical padding */
static const int sidepad                 = 15;       /* statusbar side padding */
static const int horizpadbar             = 25;
static const int vertpadbar              = 14;
static const int vertpadtab              = 42;
static const int horizpadtabi            = 15;
static const int horizpadtabo            = 15;
static const int scalepreview            = 4;
static       int tag_preview             = 0;        /* 1 means enable, 0 is off */
static const int colorfultag             = 1;        /* 0 means use SchemeSel for selected non vacant tag */

static const char *fonts[]               = { "JetBrainsMono Nerd Font:style=Medium:size=9:antialias=true",
/*static const char *fonts[]               = { "Iosevka:style=Medium:size=10:antialias=true", */
                                             "Material Design Icons-Regular:size=10:antialias=true", };

// theme
#include "themes/catppuccin.h"

static const char *colors[][3]      = {
  /*               fg         bg         border   */
    [SchemeNorm]       = { gray3, black, gray2 },
    [SchemeSel]        = { gray4, blue,  blue  },
    [TabSel]           = { blue, gray2,  black  },
    [TabNorm]          = { gray3, black, black },
    [SchemeTag]        = { gray3, black, black },
    [SchemeTag1]       = { yellow,  black, black },
    [SchemeTag2]       = { red,   black, black },
    [SchemeTag3]       = { orange, black,black },
    [SchemeTag4]       = { green, black, black },
    [SchemeTag5]       = { pink,  black, black },
    [SchemeTag6]       = { blue,   black, black },
    [SchemeTag7]       = { green, black,black },
    /*[SchemeTag8]       = { yellow, black, black },
    [SchemeTag9]       = { red,  black, black },
    [SchemeTag10]      = { pink,  black, black }, */
    [SchemeLayout]     = { yellow, black, black },
    [SchemeBtnPrev]    = { green, black, black },
    [SchemeBtnNext]    = { yellow, black, black },
    [SchemeBtnClose]   = { red, black, black },
};

/*tagging */
static char *tags[] = {"󰮯", "󰧞", "󰑊", "󰧞", "󰑊", "󰧞", "󰑊"};

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4,
                                  SchemeTag5, SchemeTag6, SchemeTag7,
                                  /*SchemeTag8, SchemeTag9, SchemeTag10 */
                                };

static const unsigned int ulinepad	    = 5;	  /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  	= 2;	  /* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;   	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		          = 0;	  /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
    /*xprop(1):
    WM_CLASS(STRING) = instance, class
    WM_NAME(STRING) = title*/
    /* class            instance    title         tags mask     iscentered   isfloating   monitor */
    { "discord",        NULL,        NULL,        1 << 5,       0,           0,            0 },
    { "YouTube Music",  NULL,        NULL,        1 << 5,       0,           0,            1 },
    { "XTerm",          NULL,        NULL,        0,            0,           1,           -1 },
    { "zoom",           NULL,        NULL,        1 << 6,       1,           1,           -1 },
    { NULL,             "fcen",      NULL,        0,            1,           1,           -1 },
    { NULL,             "fl",        NULL,        0,            0,           1,           -1 },
    { NULL,		          "spterm",	 	 NULL,		    SPTAG(0),		  1,           1,			      -1 },
  	{ NULL,		          "spfm",	   	 NULL,		    SPTAG(1),		  1,           1,			      -1 },
  	{ NULL,		          "spcalcu",   NULL,		    SPTAG(2),		  1,           1,			      -1 },
  	{ NULL,		          "spvolume",  NULL,		    SPTAG(3),		  1,           1,			      -1 },
  	{ NULL,		          "spgotop",   NULL,		    SPTAG(4),		  1,           1,			      -1 },
  	{ NULL,		          "spcurse",   NULL,		    SPTAG(5),		  0,           1,			      -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /*nrowgrid layout: force two clients to always split vertically */
#include "functions.h"


static const Layout layouts[] = {
    /* symbol     arrange function */
    { "󰊠",        tile },    /* first entry is default */
    { "[M]",      monocle },
    { "H[]",      deck },
    { "TTT",      bstack },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define FULMODKEY Mod1Mask|ShiftMask|ControlMask|Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod4Mask|ShiftMask,    KEY,      tagprevmon,     {.ui = 1 << TAG} },

/*helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *term[]  = {  "st", NULL }; // change this to your term
static const char *sscmd[] = { "scrot", "-F", "screenshot.png", "-o", "-s", "-f", "-e", "mv screenshot.png ~/personal/pictures/ && xclip -selection clipboard -target image/png -i ~/personal/pictures/screenshot.png", NULL};
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-l", "12", "-x", "650", "-y", "400", "-z", "620", NULL };
typedef struct {
      const char *name;
      const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "lfrun", NULL };
const char *spcmd3[] = {"st", "-n", "spcalcu", "-g", "80x50", "-e", "bc", "-lq", NULL };
const char *spcmd4[] = {"st", "-n", "spvolume", "-g", "115x20", "-e", "pulsemixer", NULL };
const char *spcmd5[] = {"st", "-n", "spgotop", "-g", "115x29", "-e", "gotop", NULL };
const char *spcmd6[] = {"st", "-n", "spcurse", "-g", "100x30+1200+5", "-e", "calcurse", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",       spcmd1},
    {"splf",         spcmd2},
    {"spcalcu",      spcmd3},
    {"spvolume",     spcmd4},
    {"spgotop",      spcmd5},
    {"spcurse",      spcmd6},
};


static Key keys[] = {
    /*test*/
    { MODKEY|ShiftMask|ControlMask,    XK_j,           moveresize,     {.v = "0x 25y 0w 0h" } },
	  { MODKEY|ShiftMask|ControlMask,    XK_k,           moveresize,     {.v = "0x -25y 0w 0h" } },
	  { MODKEY|ShiftMask|ControlMask,    XK_l,           moveresize,     {.v = "25x 0y 0w 0h" } },
	  { MODKEY|ShiftMask|ControlMask,    XK_h,           moveresize,     {.v = "-25x 0y 0w 0h" } },
	  { FULMODKEY,                       XK_j,           moveresize,     {.v = "0x 0y 0w 25h" } },
	  { FULMODKEY,                       XK_k,           moveresize,     {.v = "0x 0y 0w -25h" } },
	  { FULMODKEY,                       XK_l,           moveresize,     {.v = "0x 0y 25w 0h" } },
	  { FULMODKEY,                       XK_h,           moveresize,     {.v = "0x 0y -25w 0h" } },
		/*{ MODKEY,                          XK_s,           moveresize,     {.v = "0x 25y 0w 0h" } },
	  { MODKEY,                          XK_w,           moveresize,     {.v = "0x -25y 0w 0h" } },
	  { MODKEY,                          XK_d,           moveresize,     {.v = "25x 0y 0w 0h" } },
	  { MODKEY,                          XK_a,           moveresize,     {.v = "-25x 0y 0w 0h" } },
	  { MODKEY|ShiftMask,                XK_s,           moveresize,     {.v = "0x 0y 0w 25h" } },
	  { MODKEY|ShiftMask,                XK_w,           moveresize,     {.v = "0x 0y 0w -25h" } },
	  { MODKEY|ShiftMask,                XK_d,           moveresize,     {.v = "0x 0y 25w 0h" } },
		{ MODKEY|ShiftMask,                XK_a,           moveresize,     {.v = "0x 0y -25w 0h" } },*/

    /* modifier                        key             function        argument */
    { MODKEY,                          XK_q,           killclient,     {0 } },

    { MODKEY,                          XK_r,           spawn,          {.v = term }},
    { MODKEY|ShiftMask,                XK_r,           quit,           {1 } },

    { MODKEY,                          XK_t,           setlayout,      {.v = &layouts[0] } },
    { MODKEY|ControlMask,              XK_t,           togglegaps,     {0 } },

    { MODKEY,                          XK_y,           incrigaps,      {.i = +5 } },
    { MODKEY|ShiftMask,                XK_y,           incrigaps,      {.i = -5 } },

    { MODKEY,                          XK_u,           incrgaps,       {.i = +5 } },

    { MODKEY,                          XK_i,           incrgaps,       {.i = -5 } },

    { MODKEY,                          XK_o,           incrogaps,      {.i = +5 } },
    { MODKEY|ShiftMask,                XK_o,           incrogaps,      {.i = -5 } },

    { MODKEY,                          XK_p,           spawn,          {.v = dmenucmd } },
    { MODKEY|ControlMask,              XK_p,           spawn,          SHCMD("gitpass.sh") },

    { MODKEY|ControlMask|ShiftMask,    XK_d,           defaultgaps,    {0 } },

    { MODKEY,                          XK_f,           togglefullscr,  {0 } },

    { MODKEY,                          XK_g,           togglescratch,  { .ui = 4 } },

    { MODKEY,                          XK_h,           setmfact,       {.f = -0.025 } },
    { MODKEY|ShiftMask,                XK_h,           setcfact,       {.f = -0.25 } },

    { MODKEY,                          XK_j,           focusstack,     {.i = +1 } },
    { MODKEY|ShiftMask,                XK_j,           movestack,      {.i = +1 } },

    { MODKEY,                          XK_k,           focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,                XK_k,           movestack,      {.i = -1 } },

    { MODKEY,                          XK_l,           setmfact,       {.f = +0.025 } },
    { MODKEY|ShiftMask,                XK_l,           setcfact,       {.f = +0.25 } },

    { MODKEY,                          XK_semicolon,   focusmon,       {.i = -1 } },
    { MODKEY|ShiftMask,                XK_semicolon,   tagmon,         {.i = -1 } },
    { MODKEY,                          XK_apostrophe,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,                XK_apostrophe,  tagmon,         {.i = +1 } },


    { MODKEY,                          XK_z,           hidewin,        {0 } },
    { MODKEY|ShiftMask,                XK_z,           restorewin,     {0 } },

    { MODKEY|ControlMask,              XK_c,           togglescratch,  {.ui = 5} },

    { MODKEY|ControlMask,              XK_v,           togglescratch,  {.ui = 3} },

    { MODKEY,                          XK_b,           togglebar,      {0} },
    { MODKEY|ShiftMask,                XK_b,           spawn,          SHCMD("quteopen.sh") },

    { MODKEY,                          XK_m,           setlayout,      {.v = &layouts[4] } },

    { MODKEY,                          XK_n,           togglescratch,  {.ui = 1} },

    { MODKEY|ControlMask,		           XK_comma,       cyclelayout,    {.i = -1 } },
    { MODKEY|ControlMask,              XK_period,      cyclelayout,    {.i = +1 } },

    { MODKEY,                          XK_grave,       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,                XK_grave,       tag,            {.ui = ~0 } },
    TAGKEYS(                           XK_1,                           0)
    TAGKEYS(                           XK_2,                           1)
    TAGKEYS(                           XK_3,                           2)
    TAGKEYS(                           XK_4,                           3)
    TAGKEYS(                           XK_8,                           4)
    TAGKEYS(                           XK_9,                           5)
    TAGKEYS(                           XK_0,                           6)
    { MODKEY|ShiftMask,                XK_minus,       setborderpx,    {.i = -1 } },
    { MODKEY|ShiftMask|ControlMask,    XK_minus,       incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,                XK_equal, 	     setborderpx,    {.i = +1 } },
    { MODKEY|ShiftMask|ControlMask,    XK_equal,       incnmaster,     {.i = +1 } },

    { MODKEY,                          XK_F7,          spawn,          SHCMD("dmenuumount.sh") },
    { MODKEY,                          XK_F8,          spawn,          SHCMD("dmenumount.sh") },
    { MODKEY,                          XK_F9,          togglescratch,  {.ui = 2 } },
    { MODKEY,                          XK_F10,         spawn,          SHCMD("playerctl play-pause") },
    { MODKEY,                          XK_F11,         spawn,          SHCMD("playerctl previous") },
    { MODKEY,                          XK_F12,         spawn,          SHCMD("playerctl next") },

    { 0,                               XK_Print,       spawn,          {.v = sscmd } },

    { MODKEY,                          XK_Tab,         view,           {0} },

    { MODKEY,                          XK_Return,      zoom,           {0} },
    { MODKEY|ShiftMask,                XK_Return,      togglescratch,  {.ui = 0 } },

    { MODKEY,                          XK_space,       setlayout,      {0 } },
    { MODKEY|ShiftMask,                XK_space,       togglefloating, {0 } },

/*     { MODKEY|ControlMask,              XK_6,           incrihgaps,     {.i = +1 } }, */
/*     { MODKEY|ControlMask|ShiftMask,    XK_6,           incrihgaps,     {.i = -1 } }, */
/*     { MODKEY|ControlMask,              XK_7,           incrivgaps,     {.i = +1 } }, */
/*     { MODKEY|ControlMask|ShiftMask,    XK_7,           incrivgaps,     {.i = -1 } }, */
/*     { MODKEY|ControlMask,              XK_8,           incrohgaps,     {.i = +1 } }, */
/*     { MODKEY|ControlMask|ShiftMask,    XK_8,           incrohgaps,     {.i = -1 } }, */
/*     { MODKEY|ControlMask,              XK_9,           incrovgaps,     {.i = +1 } }, */
/*     { MODKEY|ControlMask|ShiftMask,    XK_9,           incrovgaps,     {.i = -1 } }, */

    /* TAGKEYS(                           XK_8,                           7) */
    /* TAGKEYS(                           XK_9,                           8) */
    /* TAGKEYS(                           XK_0,                           9) */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0 } },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0 } },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = term } },

		/* Keep movemouse? */
    /* { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} }, */

		/* placemouse options, choose which feels more natural:
		 *    0 - tiled position is relative to mouse cursor
		 *    1 - tiled postiion is relative to window center
		 *    2 - mouse pointer warps to window center
		 *
		 * The moveorplace uses movemouse or placemouse depending on the floating state
		 * of the selected client. Set up individual keybindings for the two if you want
		 * to control these separately (i.e. to retain the feature to move a tiled window
		 * into a floating position).
		 */
		{ ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         ControlMask,    Button1,        dragmfact,      {0} },
    { ClkClientWin,         ControlMask,    Button3,        dragcfact,      {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
    { ClkTabPrev,           0,              Button1,        movestack,      { .i = -1 } },
    { ClkTabNext,           0,              Button1,        movestack,      { .i = +1 } },
    { ClkTabClose,          0,              Button1,        killclient,     {0} },
};
