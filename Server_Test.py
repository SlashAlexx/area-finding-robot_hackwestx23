import requests
import time

data = {"x":"0", "y": "1", "time":"10"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data)
time.sleep(1.5)

data1 = {"x":"-1", "y": "0", "time":"15"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data1)
time.sleep(1.5)

data2 = {"x":"0", "y": "-1", "time":"50"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data2)
time.sleep(1.5)

data3 = {"x":"1", "y": "0", "time":"30"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data3)
time.sleep(1.5)

data4 = {"x":"0", "y": "1", "time":"25"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data4)
time.sleep(1.5)

data5 = {"x":"-1", "y": "0", "time":"10"}
result = requests.post("https://f51b-192-58-125-226.ngrok.io/", json=data5)
time.sleep(1.5)

# print(result.text)