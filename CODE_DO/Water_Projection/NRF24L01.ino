char NRF_Control(){
  if (radio.available()) {
   
    radio.read(&text, sizeof(text));
//    Serial.println(text);
  }
return text;
}
