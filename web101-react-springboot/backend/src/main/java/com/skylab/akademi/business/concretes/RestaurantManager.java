package com.skylab.akademi.business.concretes;

import com.skylab.akademi.business.abstracts.RestaurantService;
import com.skylab.akademi.dataAccess.RestaurantDao;
import com.skylab.akademi.entities.Restaurant;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RestaurantManager implements RestaurantService {

    private final RestaurantDao restaurantDao;

    public RestaurantManager(RestaurantDao restaurantDao) {
        this.restaurantDao = restaurantDao;
    }


    @Override
    public Restaurant addRestaurant(Restaurant restaurant) {

        if(restaurant.getName().length()<5){
            return null;
        }

        return restaurantDao.save(restaurant);
    }

    @Override
    public Restaurant getRestaurantById(int id) {

        return restaurantDao.findById(id).get();

    }

    @Override
    public List<Restaurant> getAllRestaurants() {
        return restaurantDao.findAll();
    }

    @Override
    public void deleteRestaurantById(int id) {
        restaurantDao.deleteById(id);
    }

    @Override
    public Restaurant getRestaurantByName(String name) {

        return restaurantDao.findRestaurantByName(name).get();
    }
}
