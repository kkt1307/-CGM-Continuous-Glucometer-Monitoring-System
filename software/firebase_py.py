import serial
import json
import time

import firebase_admin
from firebase_admin import credentials
from firebase_admin import db

# --------------------------------------
# CHANGE THESE
# --------------------------------------

COM_PORT = "COM3"
BAUD = 115200

SERVICE_ACCOUNT = "iitg-cgm-app-db-firebase-adminsdk-fbsvc-987bed417c.json"

DATABASE_URL = "https://iitg-cgm-app-db-default-rtdb.asia-southeast1.firebasedatabase.app/"

DEVICE_ID = "CGM001"

# --------------------------------------

cred = credentials.Certificate(SERVICE_ACCOUNT)

firebase_admin.initialize_app(
    cred,
    {
        "databaseURL": DATABASE_URL
    }
)

ref = db.reference(f"devices/{DEVICE_ID}/current")

ser = serial.Serial(COM_PORT, BAUD)

print("Connected to ESP32")

while True:

    try:

        line = ser.readline().decode().strip()

        if not line.startswith("{"):
            continue

        data = json.loads(line)

        current = float(data["sensor_current_ua"])


        glucose = min(400, current * 500)

        firebase_data = {

            "adc_raw": round(data["adc_raw"], 2),

            "battery": 100,

            "device_id": DEVICE_ID,

            "glucose": round(glucose, 1),

            "sensor_current_ua": round(current, 4),

            "status": "OK",

            "temperature": 25,

            "tia_mv": round(data["tia_mv"], 2),

            "timestamp": int(time.time())
        }   

        ref.set(firebase_data)

        print(firebase_data)

    except Exception as e:

        print(e)