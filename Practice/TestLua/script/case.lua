----获取案例元数据
---return param1: table, 地图名，table.mapName、table.zjlOdvFile、table.apolloOdvFile
---return param2: table, 天气，table.windy、table.cloudy
---return param3: table, 时间，table.hour、table.min、table.sec
---return param4: number, 持续时间
function GetMetaData()
    local caseMap = {}
    caseMap["mapName"] = "ZJL_VTS_M_AITownReconstructed_V0103_200518_Refined"
    caseMap["zjlOdvFile"] = "AITownReconstructed_V0103_200518.xodr"
    caseMap["apolloOdvFile"] = "AITownReconstructed_V0103_200518"
    local weather = {}
    weather["windy"] = 0.8
    weather["cloud"] = 0.5
    local dateTime = {}
    dateTime["hour"] = 8
    dateTime["min"] = 30
    dateTime["sec"] = 0
    local duration = 100
    return caseMap, weather, dateTime, duration
    -- return caseMap, weather, dateTime
    -- return caseMap
end