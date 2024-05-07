import time
import pyautogui

# Sleep for a few seconds to allow you to click where you want to type
time.sleep(5)

# Define the block of code you want to type
code_to_type = """
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Tweet UI</title>
<script src="https://cdn.tailwindcss.com"></script>
</head>

<body>
<div class="flex items-center justify-center h-screen">
<div class="border w-[500px] bg-black rounded-xl shadow-md overflow-hidden md:max-w-3xl m-3">
<div class="md:flex">
<div class="md:flex-shrink-0">
<span class="object-cover md:w-48 rounded-md bg-muted w-[192px] h-[192px]"></span>
</div>
<div class="p-8 w-full">
<div class="flex items-center justify-between">
<div class="flex items-center">
<img alt="Profile picture" class="rounded-full" height="40" src="/logo.png" width="40"
style="aspect-ratio:40/40;object-fit:cover" />
<div class="ml-4">
<div class="flex items-center">
<div class="tracking text-md text-white font-semibold">
CodeKage
</div>
<img src="verified.svg" alt="Verified account" class="ml-1 h-4 w-4">
</div>
<div class="text-sm" style="color: #9d9588;">
@CodeKageHQ
</div>
</div>
</div>
<img height="24" src="/x.svg" width="24" style="aspect-ratio:40/40;object-fit:cover" />
</div>
<p class="mt-4 text-white">
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec lobortis, urna eu blandit
commodo, odio nisi posuere odio, ut ultricies.
</p>
<div class="flex flex-col mt-6">
<div>
<span style="color: #9d9588;">4:22 PM Dec 27, 2023 </span>
<span style="color: white; font-weight: bold;">4.7M </span>
<span style="color: #9d9588;">Views</span>
</div>
<br>
<div class="flex justify-between space-x-4 text-gray-400">
<div class="flex items-center">
<img src="comment.svg" alt="Comment" class="h-6 w-6 text-blue-500">
<span class="ml-1" style="color: #31a4f1;">241</span>
</div>
<div class="flex items-center">
<img src="retweet.svg" alt="Retweet" class="h-6 w-6 text-green-500">
<span class="ml-1" style="color: #4affc3;">487</span>
</div>
<div class="flex items-center">
<img src="heart.svg" alt="Heart" class="h-6 w-6 text-red-500">
<span class="ml-1" style="color: #fa2c8b;">566</span>
</div>
<div class="flex items-center">
<img src="share.svg" alt="Share" class="h-6 w-6" style="fill: #31a4f1;">
<span class="ml-1" style="color: #31a4f1;">234</span>
</div>
<div class="flex items-center">
<img src="bookmark.svg" alt="Bookmark" class="h-6 w-6" style="fill: #9d9588;">
</div>
</div>
</div>
</div>
</div>
</div>
</div>
</body>

</html>
"""

# Set the typing interval to slow it down (adjust the value as needed)
typing_interval = 0.05  # 0.1 seconds (adjust as per your preference)

# Type the code with the specified interval
pyautogui.typewrite(code_to_type, interval=typing_interval)

# You can add more code to press the desired command key if needed.
# For example, to save the file, you can use:
# pyautogui.hotkey('ctrl', 's')
