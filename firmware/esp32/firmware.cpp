/*
=========================================================
 IITG CGM Prototype
 Trimmed Mean + Serial JSON Output
=========================================================

Features
---------
✓ 400 Samples
✓ Remove Highest 20
✓ Remove Lowest 20
✓ Trimmed Mean
✓ Voltage Calculation
✓ Current Calculation
✓ JSON Serial Output (for Python → Firebase)

=========================================================
*/

#include <Arduino.h>

#define TIA_PIN 34

// ADC
const float ADC_REF = 3.3;
const int ADC_MAX = 4095;

// TIA Feedback Resistor
const float RF = 20000.0;

// Sampling
const int NUM_SAMPLES = 400;
const int DISCARD = 20;
const int SAMPLE_DELAY = 2;   // ms

int adcValues[NUM_SAMPLES];

//=========================================================
// Sort
//=========================================================

void sortInt(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
}

//=========================================================

void setup()
{
  Serial.begin(115200);

  delay(1000);

  analogReadResolution(12);
  analogSetPinAttenuation(TIA_PIN, ADC_11db);

  Serial.println("ESP32 CGM Started");
}

//=========================================================

void loop()
{

  //-------------------------
  // Collect Samples
  //-------------------------

  for (int i = 0; i < NUM_SAMPLES; i++)
  {
    adcValues[i] = analogRead(TIA_PIN);
    delay(SAMPLE_DELAY);
  }

  //-------------------------
  // Sort
  //-------------------------

  sortInt(adcValues, NUM_SAMPLES);

  //-------------------------
  // Statistics
  //-------------------------

  long sum = 0;

  int minADC = adcValues[DISCARD];
  int maxADC = adcValues[NUM_SAMPLES - DISCARD - 1];

  for (int i = DISCARD; i < NUM_SAMPLES - DISCARD; i++)
  {
    sum += adcValues[i];
  }

  float avgADC = sum / float(NUM_SAMPLES - (2 * DISCARD));

  //-------------------------
  // Voltage
  //-------------------------

  float voltage = (avgADC * ADC_REF) / ADC_MAX;

  //-------------------------
  // Current
  //-------------------------

  float current = (voltage / RF) * 1000000.0;

  //-------------------------
  // JSON Output
  //-------------------------

  Serial.print("{");

Serial.print("\"adc_raw\":");
Serial.print(avgADC,2);

Serial.print(",");

Serial.print("\"tia_mv\":");
Serial.print(voltage*1000.0,2);

Serial.print(",");

Serial.print("\"sensor_current_ua\":");
Serial.print(current,4);

Serial.print(",");

Serial.print("\"timestamp\":");
Serial.print(millis());

Serial.println("}");
}


this is the code
