import sys, logging
logging.basicConfig(stream=sys.stderr, level=logging.WARNING, force=True)

import requests
from AmadeusSpeak import onChat


API_KEY = ""
personality = ""

with open("personality.txt", "r") as personalityFile:
    personality = personalityFile.read();

default_personality = [{"role" : "assistant", "content": personality}]


with open("api_key.txt", "r") as apiFile:
    API_KEY = apiFile.read()

def readContext():
    with open("memory.txt", "r") as file:
        data = file.read().strip()
        if not data:
            return []
        return eval(data)

def updateMemory(context):
    with open("memory.txt", "w") as file:
        file.write(str(context))

def getResponse(message_context):
    resp = requests.post(
        "https://openrouter.ai/api/v1/chat/completions",
        headers={
            "Authorization": f"Bearer " + API_KEY,
            "Content-Type": "application/json",
        },
        json={
            "model": "deepseek/deepseek-chat-v3.1",
            "messages": default_personality + message_context,
        },
    )
    data = resp.json()
    return data["choices"][0]["message"]["content"]


def getTranslation(assistant_reply):
    resp = requests.post(
        "https://openrouter.ai/api/v1/chat/completions",
        headers={
            "Authorization": f"Bearer " + API_KEY,
            "Content-Type": "application/json",
        },
        json={
            "model": "deepseek/deepseek-chat-v3.1",
            "messages": [{"role" : "system", "content": "translate following into japanese to be used in voice generation."}] + [{"role": "user", "content" : assistant_reply}],
        },
    )
    data = resp.json()
    return data["choices"][0]["message"]["content"]



def chat(user_message):
    context = readContext()

    context.append({"role": "user", "content": user_message})
    assistant_reply = getResponse(context)
    context.append({"role": "assistant", "content": assistant_reply})

    updateMemory(context)

    japanese_translated = getTranslation(assistant_reply)

    onChat(japanese_translated)

    return assistant_reply


if __name__ == "__main__":
    msg = sys.argv[1]
    print(chat(msg))







