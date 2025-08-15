import re
import unicodedata

import pytest


def slugify(text: str, allow_unicode:bool) -> str:
    """
    Converts a text into a URL-friendly slug.

    A note on NFC and NFKD:
    - NFC (Normalization Form C) is used to compose characters into a single character.
    - NFKD (Normalization Form KD) is used to decompose characters into their base

    Example:
        NFC: 'é' -> 'é'
        NFKD: 'é' -> 'e' + '́' (e with acute accent decomposed)

    The function performs the following transformations:
    1. Convert to lowercase.
    2. Remove leading and trailing whitespace.
    3. Replace spaces and underscores with hyphens.
    4. Replace dots and commas with hyphens.
    5. Remove non-alphanumeric characters, except for hyphens.
    6. Collapse multiple hyphens into a single one.
    7. Remove leading and trailing hyphens.
    8. If allow_unicode is True, keep unicode characters; otherwise, convert them to ASCII.
    """
    output = text.lower().strip()  # Convert to lowercase and strip whitespace
    output = re.sub(r'[\s_]+', '-', output)  # Replace spaces and underscores with hyphens
    output = re.sub(r'[.,]', '-', output)  # Replace dots and commas with hyphens
    output = re.sub(r'[^\w\s-]', '', output)  # Remove non-alphanumeric characters except hyphens
    output = re.sub(r'-+', '-', output)  # Collapse multiple hyphens into one
    output = output.strip('-')  # Remove leading and trailing hyphens

    if not allow_unicode:
        return unicodedata.normalize('NFKD', output).encode('ascii', 'ignore').decode('ascii')
    return unicodedata.normalize('NFKC', output)


@pytest.mark.parametrize("input_text, allow_unicode, slug_expected", [
    ("Hola, mundo! Python_3.10", False, "hola-mundo-python-3-10"),
    (" -- déjà vu -- ", False, "deja-vu"),
    ("¿Qué tal, César?", True, "qué-tal-césar"),
    ("Multiple   spaces", False, "multiple-spaces"),
    (" Leading and trailing spaces ", False, "leading-and-trailing-spaces"),
    ("", False, ""),
    (" ", False, ""),
    ("   \t\n  ", True, ""),
    ("  Łódź — crème brûlée!!!  ", True,  "łódź-crème-brûlée"),
    ("!!! $$$ ***", False, ""),
])
def test_slugify(input_text, allow_unicode, slug_expected):
    assert slugify(input_text, allow_unicode) == slug_expected
