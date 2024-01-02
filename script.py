import pytesseract
from PIL import Image

# Path to the Tesseract executable
# For Windows, replace with the path where Tesseract is installed, e.g., r'C:\Program Files\Tesseract-OCR\tesseract.exe'
pytesseract.pytesseract.tesseract_cmd = r'tesseract'  # For Linux/macOS, usually just 'tesseract'

# Load an image
image_path = 'image.png'
img = Image.open(image_path)

# Use Tesseract to do OCR on the image
text = pytesseract.image_to_string(img)

# Print the text
print(text)
