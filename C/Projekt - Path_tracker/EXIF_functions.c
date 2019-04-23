#include "declaration.h"

//--GETTING_LATITUDE------------------------------------------------------------------------------------------------------------------------
float get_lat(char *path)
{
    float decimal,deg,mi,sec,alt;
    char *date="ERROR",*sdeg,*smin,*ssec,*trash,*salt;
    ExifLoader *loader=exif_loader_new();
    exif_loader_write_file(loader,path);
    ExifData *data=exif_loader_get_data(loader);
    if (data!=NULL)
    {
        ExifEntry *entry_lat = exif_data_get_entry(data, EXIF_TAG_GPS_LATITUDE);
        if (entry_lat!=NULL) {
            exif_entry_get_value(entry_lat, &date, sizeof(date)+8);
            sscanf(&date,"%[^,] %s %[^,] %s %[^,]",&sdeg,&trash,&smin,&trash,&ssec);
            deg=atof(&sdeg);
            mi=atof(&smin);
            sec=atof(&ssec);
            decimal=deg+mi/60+sec/3600;

            ExifEntry *entry_latref = exif_data_get_entry(data, EXIF_TAG_GPS_LATITUDE_REF);
            if (entry_latref!=NULL)
            {
                exif_entry_get_value(entry_latref, &date, sizeof(&date));
                if (strcmp(&date,"S")==0)
                    return -decimal;
            }
            return decimal;
        }
    }
    return -1000;
}
//--GETTING_LONGTITUDE------------------------------------------------------------------------------------------------------------------------
float get_lon(char *path)
{
    float decimal,deg,mi,sec,alt;
    char *date="ERROR",*sdeg,*smin,*ssec,*trash,*salt;
    ExifLoader *loader=exif_loader_new();
    exif_loader_write_file(loader,path);
    ExifData *data=exif_loader_get_data(loader);
    if (data!=NULL)
    {
                ExifEntry *entry_lon = exif_data_get_entry(data, EXIF_TAG_GPS_LONGITUDE);
        if (entry_lon!=NULL) {
            exif_entry_get_value(entry_lon, &date, sizeof(date)+8);

            sscanf(&date,"%[^,] %s %[^,] %s %[^,]",&sdeg,&trash,&smin,&trash,&ssec);
            deg=atof(&sdeg);
            mi=atof(&smin);
            sec=atof(&ssec);
            decimal=deg+mi/60+sec/3600;

            ExifEntry *entry_lonref = exif_data_get_entry(data, EXIF_TAG_GPS_LONGITUDE_REF);
            if (entry_lonref!=NULL)
            {
                exif_entry_get_value(entry_lonref, &date, sizeof(&date));
                if (strcmp(&date,"W")==0)
                    return -decimal;
            }
            return decimal;
        }
    }
    return -1000;
}

//--GETTING_DATE------------------------------------------------------------------------------------------------------------------------
char *get_date(char *path)
{
    char *date="ERROR";
    ExifLoader *loader=exif_loader_new();
    exif_loader_write_file(loader,path);
    ExifData *data=exif_loader_get_data(loader);
    if (data!=NULL)
    {
        ExifEntry *entry;
        entry=exif_content_get_entry(data->ifd[2],EXIF_TAG_DATE_TIME_ORIGINAL);
        if (entry!=NULL)
            return entry->data;
    }
    return date;
}
