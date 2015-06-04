function getFullUserName(userlogin){
    // #Bug : fixed data
    if( userlogin == "diman" )
        return "Снежно Дмитрий Васильевич"
    if( userlogin == "11po1_8" )
        return "Снежно Дмитрий Васильевич"
    if( userlogin == "psa" )
        return "Павлович Сергей Анатольевич"
    if( userlogin == "Khaidayev" )
        return "Хайдаев Ярослав Евгеньевич"
    return qsTr("Anonymouse")
}

function reloadPermissions(userlogin){
    // #Bug : fixed data
    permission.adminRole = ( userlogin == "psa" );
}

function loginVerification(login){
    return (login.trim().toLowerCase() != "");
}


function checkLogin(login, password){
    if( loginVerification(login) ){
        var r = Math.random();
        return r > 0.25;
    }else{
        return false;
    }
}

function changeLogin(login, password){
    if( checkLogin(login, password) ){
        otherdata.userLogin = login;
        otherdata.userFullName = getFullUserName(login)
        reloadPermissions(login);
        return true;
    }else{
        console.log("Login or password uncorrectly('"+login+"','"+password+"') from user: "+otherdata.userLogin )
        return false;
    }
}
