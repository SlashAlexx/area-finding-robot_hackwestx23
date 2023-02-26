#Script is able to receive data from hosted server

from flask import Flask, request
app = Flask(__name__)

@app.route('/', methods=['POST', 'GET'])
def req():
    data = request.data.decode('utf-8')
    print(data)
    return "Received"

if __name__ == "__main__":
    app.run(port=80)