#if !defined(gui_h)
#define gui_h

enum {
	GUI_NONE = 0,
	GUI_RESTEXT = 1,
	GUI_IMAGE = 2,
	GUI_STAT = 3,
	GUI_CUSTOMTEXT = 4,
	GUI_VARTEXT = 5,
	GUI_ACTIONTEXT = 6,
	GUI_KEYTEXT = 7
};

enum {
	GWF_BORDER = 1,
	GWF_CLEARBG = 2,
	GWF_PARENT = 4,
	GWF_DELAY = 8,
	GWF_DEFAULT = GWF_BORDER|GWF_CLEARBG,
	GWF_BUTTON = GWF_BORDER|GWF_CLEARBG|GWF_DELAY

};

static const char* string_map_table_custom[] = { 
	"Master Volume :",	//0
	"Music Volume :",	//1
	"SFX Volume :",		//2
	"+",				//3
	"-",				//4
	"Sound",			//5
	"Keys",				//6
	"About",			//7
	"Pocket ScummVM",	//8
	"Build " SCUMMVM_VERSION "(" SCUMMVM_CVS ")",	//9
	"ScummVM http://scummvm.sourceforge.net",		//10
	"All games (c) LucasArts",						//11
	"Quit",											//12
	"Pause",										//13
	"Save",											//14
	"Skip",											//15
	"Hide",											//16
	"Options"										//17
};

static const byte string_map_table_v6[] = {
	117, /* How may I serve you? */
	109, /* Select a game to LOAD */
	108, /* Name your SAVE game */
	96,  /* Save */
	97,  /* Load */
	98,  /* Play */
	99,  /* Cancel */
	100, /* Quit */
	101, /* Ok */
	93  /* Game paused */
};

static const byte string_map_table_v5[] = {
	0, /* How may I serve you? */
	20, /* Select a game to LOAD */
	19, /* Name your SAVE game */
	7,  /* Save */
	8,  /* Load */
	9,  /* Play */
	10,  /* Cancel */
	11, /* Quit */
	12, /* Ok */
	4  /* Game paused */
};

struct GuiWidget {
	byte _type;
	byte _page;
	byte _flags;
	int16 _x,_y;
	uint16 _w,_h;
	uint16 _id;
	byte _string_number;
};

#define SAVEGAME_NAME_LEN 32

struct Gui {
	Scumm *_s;
	const GuiWidget *_widgets[4];
	int _return_to;
	int _curX, _curY;
	VirtScreen *_vs;
	byte _color,_shadowcolor;
	byte _bgcolor;
	byte _textcolor;
	byte _textcolorhi;
	int _parentX, _parentY;
	byte _active;
	byte _clickTimer;
	byte _cur_page;
	byte _dialog;
	int _clickWidget;
	char *_queryMess;

	/* optiondialog specifics */
	int _gui_variables[100];

	/* savedialog specifics */	
	int _slotIndex;
	int _editString;
	int _editLen;
	bool valid_games[9];
	char game_names[9][SAVEGAME_NAME_LEN];
	void loop();
	void init(Scumm *s);
	void draw(int start, int end);
	void draw(int item) { draw(item,-1); }
	void drawWidget(const GuiWidget *w);
	void moveto(int x, int y);
	void lineto(int x, int y);
	void hline(int x, int y, int x2);
	void vline(int x, int y, int y2);
	void drawChar(const char str, int xx, int yy);
	void drawString(const char *str, int x, int y, int w, byte color, bool center);
	void widgetClear(const GuiWidget *w);
	void widgetBorder(const GuiWidget *w);
	byte *getBasePtr(int x, int y);
	const GuiWidget *widgetFromPos(int x, int y);
	void leftMouseClick(int x, int y);
	void handleCommand(int cmd);
	void close();
	const char *queryString(int string, int id);
	void getSavegameNames(int start);
	void editString(int index);
	void showCaret(bool show);
	void addLetter(byte letter);	
	void queryMessage(const char *msg, const char *alts);
	byte getDefaultColor(int color);

	// Dialogs
	void saveLoadDialog();
	void pause();
	void options();
	void launcher();

	void handleSoundDialogCommand(int cmd);
	void handleOptionsDialogCommand(int cmd);
	void handleKeysDialogCommand(int cmd);
	void handleLauncherDialogCommand(int cmd);
};

// Built-in font
static byte guifont[] = {0,0,99,1,226,8,4,8,6,8,6,0,0,0,0,0,0,0,0,0,0,0,8,2,1,8,0,0,0,0,0,0,0,0,0,0,0,0,4,3,7,8,7,7,8,4,5,5,8,7,4,7,3,8,7,7,7,7,8,7,7,7,7,7,3,4,7,5,7,7,8,7,7,7,7,7,7,7,7,5,7,7,
7,8,7,7,7,7,7,7,7,7,7,8,7,7,7,5,8,5,8,8,7,7,7,6,7,7,7,7,7,5,6,7,5,8,7,7,7,7,7,7,7,7,7,8,7,7,7,5,3,5,0,8,7,7,7,7,7,7,0,6,7,7,7,5,5,5,7,0,6,8,8,7,7,7,7,7,0,7,7,0,0,
0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,1,3,6,12,
24,62,3,0,128,192,96,48,24,124,192,0,0,3,62,24,12,6,3,1,0,192,124,24,48,96,192,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,237,74,72,0,0,0,0,0,128,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,60,66,153,161,161,153,66,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,96,96,96,96,0,0,96,0,102,102,102,0,0,0,0,0,102,102,255,102,255,102,102,0,24,62,96,60,6,124,24,0,98,102,12,24,48,102,70,0,60,102,60,56,103,102,63,0,96,48,16,0,0,0,0,0,24,48,96,96,96,48,24,0,96,48,24,24,24,48,96,0,
0,102,60,255,60,102,0,0,0,24,24,126,24,24,0,0,0,0,0,0,0,48,48,96,0,0,0,126,0,0,0,0,0,0,0,0,0,96,96,0,0,3,6,12,24,48,96,0,60,102,102,102,102,102,60,0,24,24,56,24,24,24,126,0,60,102,6,12,48,96,126,0,60,102,6,28,6,102,60,0,6,
14,30,102,127,6,6,0,126,96,124,6,6,102,60,0,60,102,96,124,102,102,60,0,126,102,12,24,24,24,24,0,60,102,102,60,102,102,60,0,60,102,102,62,6,102,60,0,0,0,96,0,0,96,0,0,0,0,48,0,0,48,48,96,14,24,48,96,48,24,14,0,0,0,120,0,120,0,0,0,112,24,
12,6,12,24,112,0,60,102,6,12,24,0,24,0,0,0,0,255,255,0,0,0,24,60,102,126,102,102,102,0,124,102,102,124,102,102,124,0,60,102,96,96,96,102,60,0,120,108,102,102,102,108,120,0,126,96,96,120,96,96,126,0,126,96,96,120,96,96,96,0,60,102,96,110,102,102,60,0,102,102,102,
126,102,102,102,0,120,48,48,48,48,48,120,0,30,12,12,12,12,108,56,0,102,108,120,112,120,108,102,0,96,96,96,96,96,96,126,0,99,119,127,107,99,99,99,0,102,118,126,126,110,102,102,0,60,102,102,102,102,102,60,0,124,102,102,124,96,96,96,0,60,102,102,102,102,60,14,0,124,102,102,124,
120,108,102,0,60,102,96,60,6,102,60,0,126,24,24,24,24,24,24,0,102,102,102,102,102,102,60,0,102,102,102,102,102,60,24,0,99,99,99,107,127,119,99,0,102,102,60,24,60,102,102,0,102,102,102,60,24,24,24,0,126,6,12,24,48,96,126,0,120,96,96,96,96,96,120,0,3,6,12,24,48,
96,192,0,120,24,24,24,24,24,120,0,0,0,0,0,0,219,219,0,0,0,0,0,0,0,0,255,102,102,102,0,0,0,0,0,0,0,60,6,62,102,62,0,0,96,96,124,102,102,124,0,0,0,60,96,96,96,60,0,0,6,6,62,102,102,62,0,0,0,60,102,126,96,60,0,0,14,24,62,24,24,
24,0,0,0,62,102,102,62,6,124,0,96,96,124,102,102,102,0,0,48,0,112,48,48,120,0,0,12,0,12,12,12,12,120,0,96,96,108,120,108,102,0,0,112,48,48,48,48,120,0,0,0,102,127,127,107,99,0,0,0,124,102,102,102,102,0,0,0,60,102,102,102,60,0,0,0,124,102,102,124,96,
96,0,0,62,102,102,62,6,6,0,0,124,102,96,96,96,0,0,0,62,96,60,6,124,0,0,24,126,24,24,24,14,0,0,0,102,102,102,102,62,0,0,0,102,102,102,60,24,0,0,0,99,107,127,62,54,0,0,0,102,60,24,60,102,0,0,0,102,102,102,62,12,120,0,0,126,12,24,48,126,0,
24,48,48,96,48,48,24,0,96,96,96,0,96,96,96,0,96,48,48,24,48,48,96,0,0,0,0,0,0,0,0,0,8,12,14,255,255,14,12,8,60,102,96,96,102,60,24,56,102,0,102,102,102,102,62,0,12,24,60,102,126,96,60,0,24,36,60,6,62,102,62,0,102,0,60,6,62,102,62,0,48,
24,60,6,62,102,62,0,0,0,0,0,0,0,0,0,0,60,96,96,96,60,24,56,24,36,60,102,126,96,60,0,102,0,60,102,126,96,60,0,48,24,60,102,126,96,60,0,0,216,0,112,48,48,120,0,48,72,0,112,48,48,120,0,96,48,0,112,48,48,120,0,102,24,60,102,126,102,102,0,0,0,
0,0,0,0,0,0,24,48,124,96,120,96,124,0,0,0,108,26,126,216,110,0,30,40,40,126,72,136,142,0,24,36,60,102,102,102,60,0,102,0,60,102,102,102,60,0,48,24,60,102,102,102,60,0,24,36,0,102,102,102,62,0,48,24,102,102,102,102,62,0,0,0,0,0,0,0,0,0,102,60,102,
102,102,102,60,0,102,0,102,102,102,102,60,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,24,60,6,62,102,62,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,28,54,54,124,102,102,124,64,0,0,0};

#endif
