#!/usr/bin/env python3.7

from PIL import Image
from argparse import ArgumentParser, Namespace
from typing import Iterable


TAB = '    '


def parse_args() -> Namespace:
    parser = ArgumentParser()
    parser.add_argument('image_name', type=str, help='The graphic image')
    parser.add_argument('--multiple_elements', action='store_true')
    parser.add_argument('--element_width', type=int, help='Only valid with --multiple-elements')
    parser.add_argument('--element_height', type=int, help='Only valid with --multiple-elements')
    return parser.parse_args()


def code_for_multiple_elements(image: Image) -> Iterable[str]:
    pass


def code_for_single_element(image: Image) -> Iterable[str]:
    yield '= {\n'
    for x in range(image.width):
        if x % 8 == 0:
            yield f'{TAB}{{\n'
            yield f'{TAB}{TAB}0b'

        for y in range(image.height):
            if image.getpixel((x, y)) == 0:
                yield '1'
            else:
                yield '0'

        if x % 8 == 0:
            yield f'\n{TAB}}}\n'
    yield '}\n'


def main():
    args = parse_args()
    image = Image.open(args.image_name)
    if args.multiple_elements:
        print(''.join(code_for_multiple_elements(image, args.element_width, args.element_height)))
    else:
        print(''.join(code_for_single_element(image)))
