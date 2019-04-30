#!/usr/bin/env python3.7

from argparse import ArgumentParser, Namespace
from typing import Iterable

from PIL import Image


TAB = '    '


def parse_args() -> Namespace:
    parser = ArgumentParser()
    parser.add_argument('image_name', type=str, help='The graphic image')
    parser.add_argument('variable_name', type=str, help='The name of variable in code')
    parser.add_argument('output_file', type=str)
    parser.add_argument('--font_mode', action='store_true', help='Working with a font file (4 bits per character)')
    return parser.parse_args()


def generate_prelude_code(filename: str) -> Iterable[str]:
    yield f'#include <stdint.h>\n\n'
    yield f'/* Code generated using code_for_image.py on "{filename}". */\n\n'


def generate_code_for_font(variable_name: str, image: Image) -> Iterable[str]:
    yield from generate_prelude_code(image.filename)
    yield f'static const uint8_t {variable_name}[{image.width // 4}][{image.height}] = {{\n'

    for base_x in range(0, image.width, 4):
        yield f'{TAB}{{\n'
        for y in range(image.height):
            yield f'{TAB}{TAB}0b'

            for dx in range(4):
                if image.getpixel((base_x + dx, y)) == 0:
                    yield '1'
                else:
                    yield '0'
            yield '0000'

            yield ',\n'
        yield f'{TAB}}},\n'
    
    yield '};\n\n'

    yield f'static const uint8_t {variable_name}Shifted[{image.width // 4}][{image.height}] = {{\n'

    for base_x in range(0, image.width, 4):
        yield f'{TAB}{{\n'
        for y in range(image.height):
            yield f'{TAB}{TAB}0b0000'

            for dx in range(4):
                if image.getpixel((base_x + dx, y)) == 0:
                    yield '1'
                else:
                    yield '0'

            yield ',\n'
        yield f'{TAB}}},\n'

    yield '};\n'


def generate_code_for_image(variable_name: str, image: Image) -> Iterable[str]:
    yield from generate_prelude_code(image.filename)
    yield f'static const uint8_t {variable_name}[{image.width // 8}][{image.height}] = {{\n'

    for base_x in range(image.width - 1, -1, -8):
        yield f'{TAB}{{\n'
        for y in range(image.height):
            yield f'{TAB}{TAB}0b'

            for dx in range(-7, 1):
                if image.getpixel((base_x + dx, y)) == 0:
                    yield '1'
                else:
                    yield '0'

            yield ',\n'
        yield f'{TAB}}},\n'

    yield '};\n'


def main():
    args = parse_args()
    image = Image.open(args.image_name)
    with open(args.output_file, mode='w', encoding='utf8') as f:
        if args.font_mode:
            f.write(''.join(generate_code_for_font(args.variable_name, image)))
        else:
            f.write(''.join(generate_code_for_image(args.variable_name, image)))


main()
