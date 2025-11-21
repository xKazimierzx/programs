from django.http import HttpResponse,JsonResponse
from fps.models import Room

def index(request):
    return HttpResponse("FPS后端页面")

def GetRoomList(request):
    rooms = []
    for room in Room.objects.all().order_by('port'):
        rooms.append({
            'name':room.name,
            'port':room.port
            })
    return JsonResponse({
            'error_message':"success",
            'rooms':rooms,
     })

def BuildRoom(requset):
    for port in [25565,25566,25567]:
        if not Room.objects.filter(port=port).exists():
            room = Room.objects.create(name="房间：%d" % (port - 25564),port=port)
            return JsonResponse({
                    'error_message':"success",
                    'name':room.name,
                    'port':room.port,
                })
    return JsonResponse({
            'error_message':"no port available",
        })

def RemoveRoom(request):
    port = int(request.GET.get('port'))
    Room.objects.filter(port=port).delete()
    return JsonResponse({
            'error-message':"success",
        })
