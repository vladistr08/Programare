const decrypt = (str) => {
      const rot13String = [...str]
            .map((char) => String.fromCharCode(char.charCodeAt(0) - 13)).join('')
      return rot13String
}

const sendRequestDecrypt = () => {
      const responseLabel = document.getElementById("response-label");
      responseLabel.innerText = decrypt(responseLabel.innerText)
}

const encrypt = (str) => {
      const rot13String = [...str]
            .map((char) => String.fromCharCode(char.charCodeAt(0) + 13)).join('')
      return rot13String
}

const sendRequestEncypt = () => {
      const userPassword = document.getElementById("password-input");
      const responseLabel = document.getElementById("response-label");

      responseLabel.innerText = encrypt(userPassword.value);
      responseLabel.style.display = "block"


}