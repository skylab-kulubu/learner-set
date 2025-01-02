// restaurant.jsx
import { useEffect, useState } from "react";
import axios from "axios";
import { useLocation } from "react-router-dom";
import RestaurantHeader from "../components/restaurantHeader";
import Table from "../components/table";
import "./restaurant.css";

export default function Restaurant() {
  const location = useLocation();
  const userName = location.state?.userName || "Misafir"; // Default değer
  const [myRestaurant, setMyRestaurant] = useState(null);

  useEffect(() => {
    const fetchRestaurantData = async () => {
      try {
        const response = await axios.get("http://yusufacmaci.com:9595/api/restaurants/getAllRestaurants");
        // Veriyi çektiğimizde, ilk restoranı seçiyoruz (örnek olması adına)
        setMyRestaurant(response.data[0]);
      } catch (error) {
        console.error("Veri çekme sırasında bir hata oluştu:", error);
      }
    };

    fetchRestaurantData();
  }, []);

  return (
    <>
      {myRestaurant && (
        <>
          <RestaurantHeader restaurantName={myRestaurant.name} userName={userName} />
          <main className="restaurant">
            <article>
              <div className="windowSide">CAM KENARI</div>
              <aside className="tables">
                {myRestaurant.tables &&
                  myRestaurant.tables.map((table) => (
                    <Table
                      key={table.id}
                      index={table.id}
                      capacity={table.capacity}
                      userName={userName}
                    />
                  ))}
              </aside>
            </article>
          </main>
        </>
      )}
    </>
  );
}
