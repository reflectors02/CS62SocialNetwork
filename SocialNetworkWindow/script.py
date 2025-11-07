import requests
import sys




API_KEY = ""

with open("api_key.txt", "r") as apiFile:
    API_KEY = apiFile.read()

def readContext():
    try:
        with open("memory.txt", "r") as file:
            data = file.read().strip()
            return eval(data) if data else []
    except FileNotFoundError:
        updateMemory([])
        return []
    except json.JSONDecodeError:
    	return []


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
            "messages": message_context,
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

    return assistant_reply


if __name__ == "__main__":
    msg = sys.argv[1]
    print(chat(msg))







