import argparse
from PIL import Image
import numpy as np

parser = argparse.ArgumentParser()
parser.add_argument("input")
parser.add_argument("output")
args = parser.parse_args()

img = Image.open(args.input).convert("RGB")
img_resized = img.resize((64, 64), Image.LANCZOS)
pixels = np.array(img_resized)

output = bytearray()
for y in range(64):
    for x in range(64):
        r, g, b = pixels[y, x]
        r3 = int(r / 32) & 0x07
        g3 = int(g / 32) & 0x07
        b2 =  int(b / 64) & 0x03
        value = (r3 << 5) | (g3 << 2) | b2
        output.append(value)

with open(args.output, "wb") as f:
    f.write(output)
