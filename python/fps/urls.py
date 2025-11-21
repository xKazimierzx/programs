from django.urls import path
from fps.views import index,GetRoomList,BuildRoom,RemoveRoom

urlpatterns = [
    path("",index),
    path("GetRoomList/",GetRoomList),
    path("BuildRoom/",BuildRoom),
    path("RemoveRoom/",RemoveRoom),
]
