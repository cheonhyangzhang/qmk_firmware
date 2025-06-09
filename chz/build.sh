qmk compile -kb crkbd -km chz
qmk compile -kb boardsource/unicorne -km chz
qmk c2json -kb crkbd -km chz -o chz-keyboard.json keymap.c --no-cpp
