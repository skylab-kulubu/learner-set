// login.jsx
import "./login.css";
import { Link } from "react-router-dom";
import { useState } from "react";

export default function WelcomePage() {
  const [name, setName] = useState("");

  return (
    <main className="giris">
      <h1>Rezervasyon Uygulamasına Hoş Geldiniz</h1>
      <div>
        <form className="girisFormu" action="#">
          <h2>Giriş Yap</h2>
          <label className="infoInput" htmlFor="nameInput">
            Adınızı Giriniz
            <input
              id="nameInput"
              type="text"
              placeholder="Örn: Ali YILMAZ"
              value={name}
              onChange={(e) => setName(e.target.value)}
              required
            />
          </label>
          <Link to="/restaurant" state={{ userName: name }}>
            GİRİŞ YAP
          </Link>
        </form>
      </div>
    </main>
  );
}



