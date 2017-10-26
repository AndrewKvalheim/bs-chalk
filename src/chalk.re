type styler = string => string;

external chalk : styler = "" [@@bs.module];

/*
 * Modifiers
 */
external reset : styler = "" [@@bs.module "chalk"];

external bold : styler = "" [@@bs.module "chalk"];

external dim : styler = "" [@@bs.module "chalk"];

external italic : styler = "" [@@bs.module "chalk"];

external underline : styler = "" [@@bs.module "chalk"];

external inverse : styler = "" [@@bs.module "chalk"];

external hidden : styler = "" [@@bs.module "chalk"];

external strikethrough : styler = "" [@@bs.module "chalk"];

external visible : styler = "" [@@bs.module "chalk"];

/*
 * Colors
 */
external black : styler = "" [@@bs.module "chalk"];

external red : styler = "" [@@bs.module "chalk"];

external green : styler = "" [@@bs.module "chalk"];

external yellow : styler = "" [@@bs.module "chalk"];

external blue : styler = "" [@@bs.module "chalk"];

external magenta : styler = "" [@@bs.module "chalk"];

external cyan : styler = "" [@@bs.module "chalk"];

external white : styler = "" [@@bs.module "chalk"];

external gray : styler = "" [@@bs.module "chalk"];

external grey : styler = "" [@@bs.module "chalk"];

external redBright : styler = "" [@@bs.module "chalk"];

external greenBright : styler = "" [@@bs.module "chalk"];

external yellowBright : styler = "" [@@bs.module "chalk"];

external blueBright : styler = "" [@@bs.module "chalk"];

external magentaBright : styler = "" [@@bs.module "chalk"];

external cyanBright : styler = "" [@@bs.module "chalk"];

external whiteBright : styler = "" [@@bs.module "chalk"];

/*
 * Background colors
 */
external bgBlack : styler = "" [@@bs.module "chalk"];

external bgRed : styler = "" [@@bs.module "chalk"];

external bgGreen : styler = "" [@@bs.module "chalk"];

external bgYellow : styler = "" [@@bs.module "chalk"];

external bgBlue : styler = "" [@@bs.module "chalk"];

external bgMagenta : styler = "" [@@bs.module "chalk"];

external bgCyan : styler = "" [@@bs.module "chalk"];

external bgWhite : styler = "" [@@bs.module "chalk"];

external bgBlackBright : styler = "" [@@bs.module "chalk"];

external bgRedBright : styler = "" [@@bs.module "chalk"];

external bgGreenBright : styler = "" [@@bs.module "chalk"];

external bgYellowBright : styler = "" [@@bs.module "chalk"];

external bgBlueBright : styler = "" [@@bs.module "chalk"];

external bgMagentaBright : styler = "" [@@bs.module "chalk"];

external bgCyanBright : styler = "" [@@bs.module "chalk"];

external bgWhiteBright : styler = "" [@@bs.module "chalk"];

/*
  * 256 and Truecolor color support
 */
external rgb : (int, int, int) => styler = "" [@@bs.module "chalk"];

external hex : string => styler = "" [@@bs.module "chalk"];

external keyword : string => styler = "" [@@bs.module "chalk"];

external hsl : (int, int, int) => styler = "" [@@bs.module "chalk"];

external hsv : (int, int, int) => styler = "" [@@bs.module "chalk"];

external hwb : (int, int, int) => styler = "" [@@bs.module "chalk"];
