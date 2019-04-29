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
    parser.add_argument('--multiple_elements', action='store_true')
    parser.add_argument('--element_width', type=int, help='Only valid with --multiple-elements')
    parser.add_argument('--element_height', type=int, help='Only valid with --multiple-elements')
    return parser.parse_args()


def code_for_multiple_elements(image: Image) -> Iterable[str]:
    pass


def code_for_single_element(variable_name: str, image: Image) -> Iterable[str]:
    yield f'#include <stdint.h>\n\n'
    yield f'/* Code generated using code_for_image.py on "{image.filename}". */\n\n'
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
        if args.multiple_elements:
            f.write(''.join(code_for_multiple_elements(image, args.element_width, args.element_height)))
        else:
            f.write(''.join(code_for_single_element(args.variable_name, image)))


main()
