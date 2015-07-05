// MIDI Kanal
byte MIDIkanal = 1;

// Ton ein- oder ausschalten
byte einschalten = 144;
byte ausschalten = 128;

// Feld welches alle von der Laserharfe spielbaren Töne beinhaltet, begonnen wird mit dem Ton C
byte note[5] = {60,61,62,63,64};


void setup(){
  // Serielle Schnittsctelle für Kommunikation vorbereiten
  Serial.begin(115200);
}

// Hilfsfunktion zum senden der MIDI Signale
void MIDI_SENDEN(byte zustand, byte note, byte anschlag) 
{
  Serial.write(zustand + MIDIkanal);
  Serial.write(note);
  Serial.write(anschlag); 
}

void loop(){
        
         // Prüfen ob der Laser auf die Phototransistoren trifft, 
         // falls dies zutrifft die Note über die Serielle Schnittstelle (USB) senden.
  	if(digitalRead(A0) == LOW){
		MIDI_SENDEN(einschalten, note[0], 64);
	}

       
	if(digitalRead(A1) == LOW){
		MIDI_SENDEN(einschalten, note[1], 64);
	}
	
	if(digitalRead(A2) == LOW){
		MIDI_SENDEN(einschalten, note[2], 64);
	}
	
	if(digitalRead(A3) == LOW){
		MIDI_SENDEN(einschalten, note[3], 64);
	}

	if(digitalRead(A4) == LOW){
		MIDI_SENDEN(einschalten, note[4], 64);
	}


        // Kurz Warten
        delay(100);

}
