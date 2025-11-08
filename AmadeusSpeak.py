import os, sys, shutil
env_bin = os.path.join(sys.prefix, "bin")  
os.environ["PATH"] = env_bin + os.pathsep + os.environ.get("PATH", "")
os.environ["FFMPEG_BINARY"]  = os.path.join(env_bin, "ffmpeg")
os.environ["FFPROBE_BINARY"] = os.path.join(env_bin, "ffprobe")

import soundfile as sf
import LangSegment

LangSegment.setLangfilters = LangSegment.setfilters
LangSegment.getLangfilters = LangSegment.getfilters

from gpt_sovits_python import TTS, TTS_Config
import subprocess
import os
import sys, shutil, os

soviets_configs = {
    "default": {
        "device": "cpu",  
        "is_half": False,
        "t2s_weights_path": "pretrained_models/s1bert25hz-2kh-longer-epoch=68e-step=50232.ckpt",
        "vits_weights_path": "pretrained_models/s2G488k.pth",
        "cnhuhbert_base_path": "pretrained_models/chinese-hubert-base",
        "bert_base_path": "pretrained_models/chinese-roberta-wwm-ext-large"
    }
}

tts_config = TTS_Config(soviets_configs)
tts_pipeline = TTS(tts_config)

def generateVoice(response):
    params = {
        "text": response,                  
        "text_lang": "ja",            
        "ref_audio_path":"ttsout/kurisu10s.wav",         
        "prompt_text": "ん? ほっと来てくれませんか?ん? ふざけてないでちょっと来てくださいアニカって何ですか?人激の悪い私は",           
        "prompt_lang": "ja",            
        "top_k": 5,                   
        "top_p": 1,                   
        "temperature": 1,             
        "speed_factor": 1.0,          
        "media_type": "wav",         
        "out_path": "ttsout/generated.wav"
        }
    
    audio_gen = tts_pipeline.run(params)

    sr, wav = next(audio_gen)

    sf.write("ttsout/generated.wav", wav, sr)

    play_sound();

def play_sound():
    subprocess.run(["afplay", "ttsout/generated.wav"])


def onChat(assistant_reply):
	generateVoice(assistant_reply)
