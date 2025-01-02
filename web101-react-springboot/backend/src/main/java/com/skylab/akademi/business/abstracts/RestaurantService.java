package com.skylab.akademi.business.abstracts;

import com.skylab.akademi.entities.Restaurant;
import org.springframework.http.ResponseEntity;

import java.util.List;

public interface RestaurantService {

   Restaurant addRestaurant(Restaurant restaurant);

   Restaurant getRestaurantById(int id);

   List<Restaurant> getAllRestaurants();

   void deleteRestaurantById(int id);

   Restaurant getRestaurantByName(String name);




}
