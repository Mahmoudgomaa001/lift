#include <SPI.h> // SPI
#include <MFRC522.h> // RFID

#define SS_PIN 10
#define RST_PIN 9

// Déclaration
MFRC522 rfid(SS_PIN, RST_PIN);

// Tableau contentent l'ID
byte nuidPICC[4];

void rfidSetup()
{
  // Init RS232
  //  Serial.begin(9600);

  // Init SPI bus
  SPI.begin();

  // Init MFRC522
  rfid.PCD_Init();
}

void rfidLoop()
{
  // Initialisé la boucle si aucun badge n'est présent
  if ( !rfid.PICC_IsNewCardPresent())
    return;

  // Vérifier la présence d'un nouveau badge
  if ( !rfid.PICC_ReadCardSerial())
    return;

  // Enregistrer l'ID du badge (4 octets)
  for (byte i = 0; i < 4; i++)
  {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  // Affichage de l'ID
  Serial.println("Un badge est détecté");
  Serial.println(" L'UID du tag est:");
  String content = "";
  for (byte i = 0; i < 4; i++)
  {
    Serial.print(nuidPICC[i], HEX);

    Serial.print(" ");
    content.concat(String(nuidPICC[i], HEX));

  }
  Serial.println("");
  content.toUpperCase();
  Serial.println(content.substring(1,8));
  if (content.substring(1,8) == "D3C4A71A" || content.substring(1,8) == "D6172F1E") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
    servoOpen();
    delay(3000);
    servoClose();
  }

  else   {
    Serial.println(" Access denied");
    delay(3000);
  }
  Serial.println();

  // Re-Init RFID
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
}
