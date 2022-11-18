//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////         LECTOR QR     ///////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#define QR Serial1

TaskHandle_t Task1;

void loop2_escucha_escaner_qr(void *pvParameters)
{
  for (;;)
  {
    if (QR.available()) // Compruebe si hay datos entrantes en el búfer en serie
    {
      while (QR.available()) // Siga leyendo byte a byte desde el búfer hasta que el búfer esté vacío
      {
        char input = QR.read(); // Lee 1 byte de datos y lo guarda en una variable
        Serial.print(input);    // Imprime el byte
        delay(5);               // un pequeño retraso
      }
      Serial.println();
    }
    delay(5); // un pequeño retraso
  }

  vTaskDelay(50);
}

void setup()
{
  Serial.begin(115200);
  delay(1000);

  QR.begin(9600, SERIAL_8N1, 26, 27);
  xTaskCreatePinnedToCore(loop2_escucha_escaner_qr, "Task1", 10000, NULL, 3, &Task1, 0);
}

void loop()
{

  Serial.println("Durmiendo");
  delay(10000); // Duerme 10 segundos
  Serial.println("Despertando");
  
}
