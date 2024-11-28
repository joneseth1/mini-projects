from fastapi import FastAPI, Request
from fastapi.staticfiles import StaticFiles
from fastapi.responses import FileResponse
from pydantic import BaseModel
from chatbot_logic import get_bot_response

app = FastAPI()

app.mount("/static", StaticFiles(directory="static"), name="static")

class Message(BaseModel):
    message: str

@app.post("/chat")
async def chat(message: Message):
    user_message = message.message
    bot_response = get_bot_response(user_message)
    return {"response": bot_response}

@app.get("/")
async def get_index():
    return FileResponse("static/index.html")
