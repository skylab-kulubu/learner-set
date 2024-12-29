import "./App.css";
import Restaurant from "./pages/restaurant";
import reservationData from "./data/mockupdata";

function App() {
  return (
    <>
      <Restaurant myRestaurant={reservationData.restaurants[0]} />
    </>
  );
}

export default App;
