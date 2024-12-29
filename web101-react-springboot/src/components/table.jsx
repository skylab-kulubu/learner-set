import { useState } from "react";
import axios from "axios";
import usersSVG from "../assets/users.svg";
import "./table.css";

export default function Table({ index, capacity, userName }) {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [reservedBy, setReservedBy] = useState("");
  const [isClosing, setIsClosing] = useState(false);

  const openModal = () => {
    setIsModalOpen(true);
  };

  const closeModal = () => {
    setIsClosing(true);
    setTimeout(() => {
      setIsModalOpen(false);
      setIsClosing(false); // Animasyon bittiğinde geri resetle
    }, 500); // Animasyon süresi kadar bekle (0.5 saniye)
  };

  const handleReserve = async () => {
    try {
      const response = await axios.post(
        `http://yusufacmaci.com:9595/api/restaurantTables/reserveTable/${index}`,
        { reservedBy: userName }
      );
      setReservedBy(response.data.reservedBy);
    } catch (error) {
      console.error("Rezervasyon işlemi sırasında hata oluştu:", error);
    }
  };

  const handleCancelReservation = async () => {
    try {
      await axios.post(`http://yusufacmaci.com:9595/api/restaurantTables/cancelReservation/${index}`);
    } catch (error) {
      console.error("Rezervasyon iptal işlemi sırasında hata oluştu:", error);
    }
  };

  

  return (
    <>
      <button
        className={`table ${reservedBy && "selected"}`}
        onClick={openModal}
      >
        <h3 className="table-id">{`Table ${index}`}</h3>
        <div className="capacityDiv">
          <img src={usersSVG} alt="image depicting two persons" />
          <h4 className="capacity">{capacity}</h4>
        </div>
      </button>

      {isModalOpen && (
        <div className={`modal ${isClosing ? "fadeOut" : ""}`}>
          <div className="modal-content">
            <span className="close" onClick={closeModal}>
              x
            </span>
            <h3>{`Masa ${index} Detayları`}</h3>
            <p>{`Kapasite: ${capacity}`}</p>
            <p>{`Rezerve eden: ${reservedBy || "Henüz rezerve edilmedi"}`}</p>
            <button className="reserve-btn" onClick={handleReserve}>
              Rezerve et
            </button>
            {reservedBy && (
              <button className="cancel-btn" onClick={handleCancelReservation}>
                Rezervasyonu iptal et
              </button>
            )}
          </div>
        </div>
      )}
    </>
  );
}
