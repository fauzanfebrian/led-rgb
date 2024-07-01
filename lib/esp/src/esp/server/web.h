#ifndef WEB_CONTENT_H
#define WEB_CONTENT_H

#include <WString.h>
const String RGB_WEB_CONTENT =
    "<!DOCTYPE html>\n"
    "<html lang=\"en\">\n"
    "    <head>\n"
    "        <title>RGB Picker</title>\n"
    "        <script src=\"https://unpkg.com/vanilla-picker@2.12.3/dist/vanilla-picker.csp.min.js\"></script>\n"
    "        <link href=\"https://unpkg.com/vanilla-picker@2.12.3/dist/vanilla-picker.csp.css\" rel=\"stylesheet\" />\n"
    "    </head>\n"
    "    <body>\n"
    "        <div\n"
    "            id=\"parent\"\n"
    "            style=\"width: 400px; height: 400px; border-radius: 5px; max-width: 400px; max-height: 400px\"\n"
    "        ></div>\n"
    "        <script>\n"
    "            const urlParams = new URLSearchParams(window.location.search)\n"
    "            const rgb = urlParams.get('rgb') || ''\n"
    "            const [red, green, blue] = rgb ? rgb.split(',').map(Number) : [0, 0, 0]\n"
    "            const parent = document.querySelector('#parent')\n"
    "            const picker = new Picker({ parent, color: [red, green, blue, 1] })\n"
    "            parent.style.background = `rgba(${red}, ${green}, ${blue}, 1)`\n"
    "            picker.onChange = function (color) {\n"
    "                parent.style.background = color.rgbaString\n"
    "            }\n"
    "            picker.onDone = function (color) {\n"
    "                const [red, green, blue] = color?.rgba || []\n"
    "                window.location.search = `rgb=${red},${green},${blue}`\n"
    "            }\n"
    "            picker.show()\n"
    "        </script>\n"
    "    </body>\n"
    "</html>\n";

#endif  // WEB_CONTENT_H
