import { MatDialog, MatDialogConfig } from '@angular/material/dialog';
import { Component } from '@angular/core';
import { AddEditMovieComponent } from './add-edit-movie/add-edit-movie.component';
import { AngularFireAuth } from '@angular/fire/compat/auth';
import firebase from 'firebase/compat/app';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  email: string = 'radoter100@student.polsl.pl';
  password: string = 'AroAro';

  user: firebase.User | null = null;

  constructor(private dialog: MatDialog, protected auth: AngularFireAuth) {
    this.auth.user.subscribe(user => {
      this.user = user;
    });
  }

  login() {
    this.auth.signInWithEmailAndPassword(this.email, this.password)
      .then((userCredential) => {
        console.log('User logged in successfully', userCredential.user);
      })
      .catch((error) => {
        console.log('Error signing in', error);
      });
  }

  loginWithGoogle() {
    this.auth.signInWithPopup(new firebase.auth.GoogleAuthProvider())
      .then((userCredential) => {
        console.log('User logged in successfully', userCredential.user);
      })
      .catch((error) => {
        console.log('Error signing in', error);
      });
  }

  logout() {
    this.auth.signOut();
  }

  openAddMovieDialog() {
    const dialogConfig = new MatDialogConfig();
    dialogConfig.data = {
      operation: 'ADD'
    };
    this.dialog.open(AddEditMovieComponent, dialogConfig);
  }
}
