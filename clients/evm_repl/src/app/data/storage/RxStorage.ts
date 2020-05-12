import localforage from "localforage";
import { Observable, Observer, of } from "rxjs";
import { map, mergeMap } from "rxjs/operators";
import _ from "lodash";
import { Optional } from "../../shared/Optional";

export class RxStorage<T> {
  entityName: string;

  constructor(entityName: string) {
    this.entityName = entityName;
  }

  getItem(): Observable<Optional<T>> {
    return Observable.create((observer: Observer<Optional<T>>) => {
      localforage
        .getItem(this.entityName)
        .then((value) => {
          if (value != null) {
            observer.next(value as T);
          } else {
            observer.next(undefined);
          }
          observer.complete();
        })
        .catch((err) => observer.error(err));
    });
  }

  insertItem(value: T | T[]): Observable<void> {
    return Observable.create((observer: Observer<void>) => {
      localforage
        .setItem(this.entityName, value)
        .then(() => {
          observer.next(void 0);
          observer.complete();
        })
        .catch((err) => {
          observer.error(err);
        });
    });
  }

  removeItem(): Observable<void> {
    return Observable.create((observer: Observer<void>) => {
      localforage
        .removeItem(this.entityName)
        .then(() => {
          observer.next(void 0);
          observer.complete();
        })
        .catch((err) => observer.error(err));
    });
  }

  getItems(): Observable<T[]> {
    return Observable.create((observer: Observer<T[]>) => {
      localforage
        .getItem(this.entityName)
        .then((value) => {
          if (value != null) {
            observer.next(value as T[]);
          } else {
            observer.next([]);
          }
          observer.complete();
        })
        .catch((err) => observer.error(err));
    });
  }

  insertInto(value: T): Observable<void> {
    return this.getItems().pipe(
      map((list) => {
        const nextList: Array<T> = list || Array<T>();
        nextList.push(value);
        return nextList;
      }),
      mergeMap((list) => this.insertItem(list))
    );
  }

  insertAll(values: T[]): Observable<void> {
    return this.getItems().pipe(
      map((list) => {
        const nextList: Array<T> = list || Array<T>();
        nextList.push(...values);
        return nextList;
      }),
      mergeMap((list) => this.insertItem(list))
    );
  }

  filterReplace(predicate: (e: T) => boolean): Observable<void> {
    return this.getItems().pipe(
      mergeMap((list) => {
        if (list != null) {
          const results = _.filter(list, predicate);
          return this.insertItem(results);
        } else {
          return of(void 0);
        }
      })
    );
  }

  find(predicate: (e: T) => boolean): Observable<T | null> {
    return this.getItems().pipe(
      map((items) => {
        if (items != null) {
          const result = _.find(items, predicate);
          if (result != null && result !== undefined) return result;
          return null;
        }
        return null;
      })
    );
  }

  filter(predicate: (e: T) => boolean): Observable<T[] | null> {
    return this.getItems().pipe(
      map((items) => {
        if (items != null) {
          const results = _.filter(items, predicate);
          if (results != null && results !== undefined) return results;
          return null;
        }
        return null;
      })
    );
  }

  exists(predicate: (e: T) => boolean): Observable<boolean> {
    return this.find(predicate).pipe(
      map((result) => {
        if (result != null) return true;
        return false;
      })
    );
  }

  static clear(): Observable<void> {
    return Observable.create((observer: Observer<void>) => {
      localforage
        .clear()
        .then(() => {
          observer.next(void 0);
          observer.complete();
        })
        .catch((err) => observer.error(err));
    });
  }
}
