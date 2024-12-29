// restaurantHeader.jsx

import userSVG from "../assets/user.svg";
import restaurantIcon from "../assets/restaurant.svg";
import "./restaurantHeader.css";

export default function RestaurantHeader({ restaurantName, userName }) {
  return (
    <nav className="restaurantNav">
      <div className="resApp">
        <img className="svg" src={restaurantIcon} alt="Restaurant Icon" />
        <h1>RESAPP</h1>
      </div>
      <h1 className="restaurantName">{restaurantName}</h1>
      <div className="userDetails">
        <img className="svg" src={userSVG} alt="svg depicting user" />
        <h2>{userName}</h2> 
      </div>
    </nav>
  );
}
